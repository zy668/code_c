#include <stdio.h>
#define maxsize 100
typedef struct stack
{
    char data[maxsize];
    int top;
} stack;
void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("empty");
        return;
    }
    s->top--;
}
void push(stack *s, char c)
{
    if (s->top == maxsize - 1)
    {
        printf("full");
        return;
    }
    s->top++;
    s->data[s->top] = c;
}
int main()
{
    int ch, count = 0;
    stack s;
    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            if (s.top == -1 || s.data[s.top] != '(')
            {
                printf("no");
                return 0;
            }
            else
            {
                pop(&s);
                count++;
            }
        }
        else if (ch == ']')
        {
            if (s.top == -1 || s.data[s.top] != '[')
            {
                printf("no");
                return 0;
            }
            else
            {
                pop(&s);
                count++;
            }
        }
        else if (ch == '}')
        {
            if (s.top == -1 || s.data[s.top] != '{')
            {
                printf("no");
                return 0;
            }
            else
            {
                pop(&s);
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}