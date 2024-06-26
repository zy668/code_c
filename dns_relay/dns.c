#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h> // Include this for other network functions

// 定义 DNS 协议头部的结构
typedef struct
{
  unsigned short id; // 会话标识

  unsigned char rd : 1;     // 递归请求
  unsigned char tc : 1;     // 消息截断
  unsigned char aa : 1;     // 授权回答
  unsigned char opcode : 4; // 操作码
  unsigned char qr : 1;     // 查询/响应标志，0为查询，1为响应

  unsigned char rcode : 4; // 响应码
  unsigned char cd : 1;    // 检查禁用
  unsigned char ad : 1;    // 认证数据
  unsigned char z : 1;     // 保留为0
  unsigned char ra : 1;    // 递归可用

  unsigned short q_count;    // 问题数
  unsigned short ans_count;  // 回答数
  unsigned short auth_count; // 授权数
  unsigned short add_count;  // 附加信息数
} DNS_HEADER;

// DNS 查询问题部分
typedef struct
{
  char qname[256];       // 域名字符串
  unsigned short qtype;  // 查询类型（例如：A = 1, MX = 15等）
  unsigned short qclass; // 查询类（通常是IN = 1）
} DNS_QUESTION;

void parse_dns_query_name(unsigned char *reader, unsigned char *buffer, char *output)
{
  int p = 0;
  int jumped = 0;
  int offset = 0;
  int is_first = 1;

  while (*reader != 0)
  {
    if (*reader >= 192)
    {
      offset = ((*reader) * 256 + *(reader + 1)) - 49152;
      reader = buffer + offset - 2;
      jumped = 1;
    }
    else
    {
      if (!is_first)
      {
        output[p++] = '.';
      }
      for (int i = 0; i < *reader; i++)
      {
        output[p++] = *(reader + 1 + i);
      }
      reader = reader + *reader + 1;
      is_first = 0;
    }
  }
  output[p] = '\0';

  if (jumped)
  {
    reader += 2;
  }
}

void send_query_to_upstream_dns(SOCKET sockfd, const char *upstream_dns_ip, int upstream_dns_port, char *request, int request_len, struct sockaddr_in *client_addr)
{
  struct sockaddr_in upstream_addr;
  memset(&upstream_addr, 0, sizeof(upstream_addr));
  upstream_addr.sin_family = AF_INET;
  upstream_addr.sin_port = htons(upstream_dns_port);
  upstream_addr.sin_addr.s_addr = inet_addr(upstream_dns_ip);

  if (sendto(sockfd, request, request_len, 0, (struct sockaddr *)&upstream_addr, sizeof(upstream_addr)) < 0)
  {
    perror("sendto failed");
    return;
  }
}

int receive_response_from_upstream_dns(SOCKET sockfd, char *response, int max_response_size, struct sockaddr_in *from_addr, int *from_len)
{
  int recv_len = recvfrom(sockfd, response, max_response_size, 0, (struct sockaddr *)from_addr, from_len);
  if (recv_len < 0)
  {
    perror("recvfrom failed");
  }
  return recv_len;
}

void forward_response_to_client(SOCKET sockfd, char *response, int response_len, struct sockaddr_in *client_addr, int client_len)
{
  if (sendto(sockfd, response, response_len, 0, (struct sockaddr *)client_addr, client_len) < 0)
  {
    perror("sendto failed");
  }
}

int main()
{
  WSADATA wsaData;
  SOCKET sockfd;
  struct sockaddr_in server, client;
  char buffer[1024];
  int client_len, recv_len;

  const char *upstream_dns_ip = "10.3.9.4"; // 这里使用Google的DNS服务器地址
  int upstream_dns_port = 53;

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
  {
    printf("WSAStartup failed. Error Code : %d\n", WSAGetLastError());
    exit(EXIT_FAILURE);
  }

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
  {
    printf("Could not create socket : %d\n", WSAGetLastError());
    exit(EXIT_FAILURE);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(53);

  if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
  {
    printf("Bind failed with error code : %d\n", WSAGetLastError());
    closesocket(sockfd);
    WSACleanup();
    exit(EXIT_FAILURE);
  }

  printf("Waiting for data...\n");
  fflush(stdout);
  client_len = sizeof(struct sockaddr_in);

  while ((recv_len = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&client, &client_len)) != SOCKET_ERROR)
  {
    printf("Received a packet\n");

    // 解析DNS头部
    DNS_HEADER *dns = (DNS_HEADER *)buffer;
    printf("Transaction ID: %hu\n", ntohs(dns->id));
    printf("Questions: %hu\n", ntohs(dns->q_count));

    // 获取问题部分的开始位置
    unsigned char *reader = (unsigned char *)buffer + sizeof(DNS_HEADER);

    // 为了支持多个查询，我们可以循环处理每个查询
    for (int i = 0; i < ntohs(dns->q_count); ++i)
    {
      DNS_QUESTION question;
      parse_dns_query_name(reader, buffer, question.qname); // 解析并存储域名

      // 跳过域名部分
      reader += strlen(question.qname) + 2; // +2 为跳过域名后的两个 null 字节

      // 读取并存储查询类型和类别
      question.qtype = ntohs(*(unsigned short *)reader);
      reader += sizeof(unsigned short);
      question.qclass = ntohs(*(unsigned short *)reader);
      reader += sizeof(unsigned short);

      // 打印解析的查询请求信息
      printf("Received DNS query:\n");
      printf("Transaction ID: %hu\n", ntohs(dns->id));
      printf("Domain Name: %s\n", question.qname);
      printf("Query Type: %d\n", question.qtype);
      printf("Query Class: %d\n", question.qclass);
    }

    // 向上级DNS服务器发送查询
    send_query_to_upstream_dns(sockfd, upstream_dns_ip, upstream_dns_port, buffer, recv_len, &client);

    // 接收上级DNS服务器的响应
    struct sockaddr_in from_addr;
    int from_len = sizeof(from_addr);
    int response_len = receive_response_from_upstream_dns(sockfd, buffer, sizeof(buffer), &from_addr, &from_len);

    // 将响应转发回客户端
    forward_response_to_client(sockfd, buffer, response_len, &client, client_len);
  }

  if (recv_len == SOCKET_ERROR)
  {
    printf("recvfrom() failed with error code : %d\n", WSAGetLastError());
  }

  closesocket(sockfd);
  WSACleanup();
  return 0;
}
