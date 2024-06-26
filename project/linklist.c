#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct linklist
{
  int val;
  struct linklist *next;

} node;
node *Create(void)
{
  node *head = (node *)malloc(sizeof(node));
  head->next = NULL;
  head->val = 0;
  return head;
}
int Verify(node *head)
{
  if (head == NULL || head->next == NULL)
  {
    printf("Empty");
    return 1;
  }
  node *temp = head->next;
  while (temp != NULL && temp->next != NULL)
  {
    if (temp->val > temp->next->val)
    {
      return 0;
    }
    temp = temp->next;
  }
  return 1;
}
void Insert(node *head, int val)
{
  if (head == NULL)
  {
    printf("linklist has not been created!\n");
    return;
  }
  head->val++;
  node *new_node = Create();
  new_node->val = val;

  node *temp = head;
  while (temp->next != NULL && temp->next->val < val)
  {
    temp = temp->next;
  }

  new_node->next = temp->next;
  temp->next = new_node;
}

void Revert(node *head)
{
  if (head == NULL || head->next == NULL)
  {
    printf("Error!\n");
    return;
  }
  node *pre = NULL;
  node *cur = head->next;
  node *next = NULL;
  while (cur != NULL)
  {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  head->next = pre;
}
void Delete(node *head, int val)
{
  if (head == NULL || head->next == NULL)
  {
    printf("empty!\n");
    return;
  }
  node *cur = head->next;
  node *pre = head;
  while (cur != NULL)
  {
    if (cur->val == val)
    {
      pre->next = cur->next;
      free(cur);
      head->val--;
      cur = pre->next;
    }
    else
    {
      pre = cur;
      cur = cur->next;
    }
  }
}
void Destroy(node *head)
{
  node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void Dump(node *head)
{
  if (head == NULL || head->next == NULL)
  {
    printf("empty!\n");
    return;
  }
  node *temp = head->next;
  while (temp != NULL)
  {
    printf("%d ", temp->val);
    temp = temp->next;
  }
  putchar('\n');
}
int Count(node *head)
{
  if (head == NULL)
  {
    printf("Empty");
    return 0;
  }
  return head->val;
}
long long Sum(node *head)
{
  if (head == NULL)
  {
    printf("empty");
    return 0;
  }
  node *temp = head->next;
  long long total = 0;
  while (temp != NULL)
  {
    total += temp->val;
    temp = temp->next;
  }
  return total;
}
int main(void)
{
  char input[20] = "";
  int data;
  node *head = NULL;
  while (1)
  {
    scanf("%s", input);
    if (strcmp(input, "create") == 0)
    {
      head = Create();
    }
    else if (strcmp(input, "insert") == 0)
    {
      scanf("%d", &data);
      Insert(head, data);
    }
    else if (strcmp(input, "delete") == 0)
    {
      scanf("%d", &data);
      Delete(head, data);
    }
    else if (strcmp(input, "revert") == 0)
    {
      Revert(head);
    }
    else if (strcmp(input, "dump") == 0)
    {
      Dump(head);
    }
    else if (strcmp(input, "verify") == 0)
    {
      if (Verify(head))
      {
        printf("Yes!\n");
      }
      else
      {
        printf("No!\n");
      }
    }
    else if (strcmp(input, "count") == 0)
    {
      printf("%d\n", Count(head));
    }
    else if (strcmp(input, "sum") == 0)
    {
      printf("%lld\n", Sum(head));
    }
    else if (strcmp(input, "destroy") == 0)
    {
      Destroy(head);
    }
    else if (strcmp(input, "bye") == 0)
    {
      printf("bye!\n");
      break;
    }
    else
    {
      printf("Illegal input!\n");
    }
  }
  return 0;
}