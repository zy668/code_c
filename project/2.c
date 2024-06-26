#include <stdio.h>
void swap(char *a,char *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void permutation(char a[], int start, int end)
{
	int i;
	if (start == end)
	{
		for (i = 0; i <= end; i++)
		{
			printf("%c ", a[i]);
		}
		putchar('\n');
	}
	else
	{
		for (i = start; i <= end; i++)
		{
			swap(&a[start], &a[i]);
			permutation(a, start + 1, end);
			swap(&a[start], &a[i]);
		}
	}
}
int main()
{
	char s[4] = "abc";
	permutation(s, 0, 2);
	return 0;
}