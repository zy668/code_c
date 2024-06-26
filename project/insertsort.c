#include <stdio.h>
#include <stdlib.h>
typedef struct linklist
{
  int val;
  struct linklist *next;
} node;
node *insertsort(node *head)
{
  node dum;
  dum.next = head;
  node *cur = head->next;
  while (cur != NULL)
  {
  }
}
int main()
{

  return 0;
}