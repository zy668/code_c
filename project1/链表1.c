#include <stdio.h>
#include <stdlib.h>
typedef struct linklist
{
	int val;
	struct linklist *next;
} node;
void clear(node *a)
{
	node *b = a->next;
	node *c;
	while (a)
	{
		c = a;
		b = a->next;
		free(a);
		a = b;
		c = NULL;
	}
}
int main()
{
	node *last = NULL;
	node *head = NULL;
	int n, i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &n);
		node *p = (node *)malloc(sizeof(node));
		p->val = n;
		p->next = NULL;
		if (head != NULL)
		{
			last->next = p;
		}
		else
		{
			head = p;
			last = head;
		}
		if (last->next)
		{
			last = last->next;
		}
	}
	node *a = head;
	while (a)
	{
		printf("%d ", a->val);
		a = a->next;
	}
	clear(head);
	return 0;
}
