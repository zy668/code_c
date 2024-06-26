#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linklist
{
  int val;
  struct linklist *next;
  struct linklist *prev;
} node;

node *Create(void)
{
  node *head = (node *)malloc(sizeof(node));
  head->next = head;
  head->prev = head;
  head->val = 0;
  return head;
}

void Insert(node *head, int val)
{
  if (head == NULL)
  {
    printf("linklist has not been created!\n");
    return;
  }
  node *new_node = (node *)malloc(sizeof(node));
  new_node->val = val;

  node *temp = head->next;
  while (temp != head && temp->val < val)
  {
    temp = temp->next;
  }
  new_node->next = temp;
  new_node->prev = temp->prev;
  temp->prev->next = new_node;
  temp->prev = new_node;

  head->val++;
}
int Verify(node *head)
{
  if (head == NULL || head->next == head)
  {
    printf("Empty");
    return 1;
  }

  node *temp = head->next;
  while (temp->next != head)
  {
    if (temp->val > temp->next->val)
    {
      return 0;
    }
    temp = temp->next;
  }
  return 1;
}
void Revert(node *head)
{
  if (head == NULL || head->next == head)
  {
    printf("empty!\n");
    return;
  }

  node *original_first = head->next;
  node *original_last = head->prev;

  node *cur = original_first;
  do
  {
    node *temp = cur->next;
    cur->next = cur->prev;
    cur->prev = temp;
    cur = temp;
  } while (cur != original_first);

  head->next = original_last;
  head->prev = original_first;
}

void Delete(node *head, int val)
{
  if (head == NULL)
  {
    printf("linklist has not been created!\n");
    return;
  }
  node *cur = head->next;
  while (cur != head)
  {
    if (cur->val == val)
    {
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      node *temp = cur;
      cur = cur->next;
      free(temp);
      head->val--;
    }
    else
    {
      cur = cur->next;
    }
  }
}

void Dump(node *head)
{
  if (head == NULL)
  {
    printf("linklist has not been created");
  }
  node *temp = head->next;
  while (temp != head)
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
    printf("Empty!");
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
  long long total = 0;
  for (node *temp = head->next; temp != head; temp = temp->next)
  {
    total += temp->val;
  }
  return total;
}

void Destroy(node *head)
{
  if (head == NULL)
  {
    return;
  }
  node *temp = head->next;
  while (temp != head)
  {
    node *next = temp->next;
    free(temp);
    temp = next;
  }
  free(head);
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
      if (Verify(head) == 1)
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