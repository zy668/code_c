#include <stdio.h>
#include <stdlib.h>
#define maxsize 50
typedef struct stack
{
  char bracket[maxsize];
  int top;
} stack;
stack *create(void)
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = -1;
  return s;
}
char match(char right)
{
  switch (right)
  {
  case ')':
    return '(';
  case ']':
    return '[';
  case '}':
    return '{';
  default:
    return '\0';
  }
}
int isFull(stack *s)
{
  if (s->top == maxsize - 1)
  {
    return 1;
  }
  return 0;
}
int isEmpty(stack *s)
{
  if (s->top == -1)
  {
    return 1;
  }
  return 0;
}
void push(stack *s, char ch)
{
  if (isFull(s))
  {
    printf("Full\n");
    return;
  }
  s->bracket[++s->top] = ch;
}
char pop(stack *s)
{
  if (isEmpty(s))
  {
    printf("empty\n");
    return '\0';
  }
  return s->bracket[s->top--];
}
char peek(stack *s)
{
  if (isEmpty(s))
  {
    printf("empty\n");
    return '\0';
  }
  return s->bracket[s->top];
}
int main(void)
{
  int ch;
  stack *s = create();
  while ((ch = getchar()) != '\n')
  {
    if (ch == '(' || ch == '{' || ch == '[')
    {
      push(s, ch);
    }
    else if (ch == ')' || ch == '}' || ch == ']')
    {
      if (isEmpty(s) || peek(s) != match(ch))
      {
        printf("mismatch");
        free(s);
        return 0;
      }
      else
      {
        pop(s);
      }
    }
  }
  if (isEmpty(s))
  {
    printf("match");
  }
  else
  {
    printf("mismatch");
  }
  free(s);
  return 0;
}