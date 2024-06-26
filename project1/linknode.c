#include <stdio.h>
#include <stdlib.h>
typedef struct linklist
{
  int val;
  struct linklist *next;
} node;
// 倒序打印链表
void rev(node *head)
{
  if (head == NULL)
  {
    return;
  }
  rev(head->next);
  printf("%d ", head->val);
}
node *create(int val)
{
  node *head = malloc(sizeof(node));
  head->val = val;
  head->next = NULL;
  return head;
}
void insert(node *head, int val)
{
  // node *new = malloc(sizeof(node));
  // new->next = NULL;
  // new->val = val;
  node *new = create(val);
  while (head->next)
  {
    head = head->next;
  }
  head->next = new;
}
int main()
{
  node *head = create(1);
  for (int i = 2; i < 10; i++)
  {
    insert(head, i);
  }
  rev(head);
  return 0;
}