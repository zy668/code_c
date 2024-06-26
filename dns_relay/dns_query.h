#include <stdint.h>
// DNS header structure
typedef struct
{
  uint16_t id; // 标识符

  uint8_t rd : 1;     // 递归期望
  uint8_t tc : 1;     // 截断消息
  uint8_t aa : 1;     // 授权回答
  uint8_t opcode : 4; // 操作码
  uint8_t qr : 1;     // 查询/响应标志，0为查询，1为响应

  uint8_t rcode : 4; // 响应码
  uint8_t cd : 1;    // 检查禁用
  uint8_t ad : 1;    // 认证的数据
  uint8_t z : 1;     // 保留为0
  uint8_t ra : 1;    // 递归可用

  uint16_t qdcount; // 问题数
  uint16_t ancount; // 回答记录数
  uint16_t nscount; // 授权记录数
  uint16_t arcount; // 附加记录数
} dns_header_t;

// Question section format
typedef struct
{
  char *qname;     // 域名
  uint16_t qtype;  // 问题类型
  uint16_t qclass; // 问题类
} dns_question_t;
