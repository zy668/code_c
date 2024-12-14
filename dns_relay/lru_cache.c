#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int CAPACITY = 0;
#define TABLE_SIZE (CAPACITY * 4 / 3 + 1)

typedef struct cache_node
{
  char domain[256];
  char ip[40];
  struct cache_node *next;  // 双向链表的前驱
  struct cache_node *prev;  // 双向链表的后继
  struct cache_node *hnext; // 哈希链表的后继
} cache_node;               // 缓存dns表项

typedef struct cache
{
  cache_node **table; // 哈希表，用于通过domain获取对应cache_node
  cache_node *head;   // 虚拟头节点，head->next指向最近访问的节点
  cache_node *tail;   // 虚拟尾节点，tail->prev指向最久未访问的节点
  int size;           // 当前缓存的大小
  int capacity;       // 缓存的容量
} cache;

// 哈希函数，根据域名计算哈希值
unsigned int hash(const char *domain)
{
  unsigned int hash_value = 5381;
  for (int i = 0; domain[i]; i++)
  {
    hash_value = (hash_value << 5) + hash_value + domain[i];
  }
  return hash_value % TABLE_SIZE;
}
// 创建缓存表
cache *create_cache(int capacity)
{
  CAPACITY = capacity;
  cache *c = (cache *)malloc(sizeof(cache));
  c->head = malloc(sizeof(cache_node));
  c->tail = malloc(sizeof(cache_node));
  c->head->next = c->tail;
  c->head->prev = NULL;
  c->tail->next = NULL;
  c->tail->prev = c->head;
  c->size = 0;
  c->capacity = capacity;
  c->table = (cache_node **)malloc(sizeof(cache_node *) * TABLE_SIZE);
  memset(c->table, 0, sizeof(cache_node *) * TABLE_SIZE);
  return c;
}
// 创建新节点
cache_node *create_cache_node(char *domain, char *ip)
{
  cache_node *node = malloc(sizeof(cache_node));
  strcpy(node->domain, domain);
  strcpy(node->ip, ip);
  node->next = NULL;
  node->prev = NULL;
  node->hnext = NULL;
  return node;
}
// 移出节点
void remove_node(cache *c, cache_node *node)
{
  node->prev->next = node->next;
  node->next->prev = node->prev;
}
// 添加到头部
void add_to_head(cache *c, cache_node *node)
{
  node->next = c->head->next;
  c->head->next->prev = node;
  node->prev = c->head;
  c->head->next = node;
}
// 移动节点到头部
void move_node(cache *c, cache_node *node)
{
  remove_node(c, node);
  add_to_head(c, node);
}

void delete_tail(cache *c)
{
  if (c->tail->prev == c->head)
  {
    return;
  }
  cache_node *node = c->tail->prev;
  remove_node(c, node);

  int index = hash(node->domain);
  cache_node *prev = NULL;
  cache_node *cur = c->table[index];
  while (cur != NULL)
  {
    if (cur == node)
    {
      if (prev == NULL)
      {
        c->table[index] = cur->hnext;
      }
      else
      {
        prev->hnext = cur->hnext;
      }
      break;
    }
    prev = cur;
    cur = cur->hnext;
  }

  free(node);
  c->size--;
}

// 将新节点插入到哈希表的头部
void put(cache *c, char *domain, char *ip)
{
  int index = hash(domain);
  cache_node *cur = c->table[index];

  // 如果domain已经存在，更新ip并移动到头部
  while (cur != NULL)
  {
    if (strcmp(cur->domain, domain) == 0)
    {
      strcpy(cur->ip, ip); // 更新ip
      move_node(c, cur);   // 移动到头部
      return;
    }
    cur = cur->hnext;
  }

  // 如果domain不存在，创建新的cache_node并插入到头部
  cache_node *node = create_cache_node(domain, ip);
  node->hnext = c->table[index]; // 哈希表头插法
  c->table[index] = node;
  add_to_head(c, node);
  c->size++;

  // 如果缓存超过容量，删除尾部节点
  if (c->size > c->capacity)
  {
    delete_tail(c);
  }
}

// 通过domain获取ip
char *get(cache *c, char *domain)
{
  int index = hash(domain);
  cache_node *cur = c->table[index];
  while (cur != NULL)
  {
    if (strcmp(cur->domain, domain) == 0)
    {
      move_node(c, cur);
      return cur->ip;
    }
    cur = cur->hnext;
  }
  return NULL;
}

int main()
{
  cache *c = create_cache(3);
  printf("table_size: %d\n", TABLE_SIZE);
  put(c, "example.com", "192.168.1.1");
  put(c, "example.net", "192.168.1.2");
  put(c, "example.org", "192.168.1.3");

  printf("IP of example.com: %s\n", get(c, "example.com"));
  printf("IP of example.net: %s\n", get(c, "example.net"));
  printf("IP of example.org: %s\n", get(c, "example.org"));

  put(c, "example.edu", "192.168.1.4"); // This will cause eviction

  printf("IP of example.com: %s\n", get(c, "example.com")); // This should return NULL
  printf("IP of example.net: %s\n", get(c, "example.net"));
  printf("IP of example.org: %s\n", get(c, "example.org"));
  printf("IP of example.edu: %s\n", get(c, "example.edu"));

  return 0;
}
