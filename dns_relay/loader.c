#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 1217 // 素数，且大于911

typedef struct dns_entry
{
  char domain[256];
  char ip_address[16];
  struct dns_entry *next; // 使用链表法解决哈希冲突
} dns_entry;              // DNS表项

dns_entry *static_table[TABLE_SIZE]; // 静态DNS表

// 哈希函数，根据域名计算哈希值
unsigned int hash(const char *domain, int size)
{
  unsigned int hash_value = 5381;
  for (int i = 0; domain[i]; i++)
  {
    hash_value = (hash_value << 5) + hash_value + domain[i];
  }
  return hash_value % size;
}

// 插入DNS记录到哈希表
void insert_dns_entry(const char *domain, const char *ip_address)
{
  unsigned int index = hash(domain, TABLE_SIZE);
  dns_entry *new_entry = malloc(sizeof(dns_entry));
  strcpy(new_entry->domain, domain);
  strcpy(new_entry->ip_address, ip_address);
  new_entry->next = static_table[index];
  static_table[index] = new_entry;
}

// 从文件加载静态DNS表
void load_static_dns_table(const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (!file)
  {
    perror("Failed to open file");
    return;
  }
  char domain[256];
  char ip_address[16];
  while (fscanf(file, "%s %s", ip_address, domain) != EOF)
  {
    insert_dns_entry(domain, ip_address);
  }
  fclose(file);
}

// 查询静态DNS记录
char *query_static_dns(const char *domain)
{
  unsigned int index = hash(domain, TABLE_SIZE);
  dns_entry *entry = static_table[index];
  while (entry)
  {
    if (strcmp(entry->domain, domain) == 0)
    {
      return entry->ip_address;
    }
    entry = entry->next;
  }
  return NULL; // 没有找到对应记录
}

// 初始化静态DNS表
void init_static_dns_table()
{
  memset(static_table, 0, sizeof(static_table));
}
int main()
{
  // 初始化静态DNS表
  init_static_dns_table();

  // 加载静态DNS表
  load_static_dns_table("dnsrelay.txt");

  while (1)
  {
    char domain[256];
    printf("Enter a domain name: ");
    scanf("%s", domain);
    char *ip = query_static_dns(domain);
    if (ip)
    {
      printf("IP address of %s is %s\n", domain, ip);
    }
    else
    {
      printf("No record found for %s\n", domain);
    }
  }

  return 0;
}