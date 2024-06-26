#include <stdio.h>

int main()
{
	int n = 100; // 设置循环的上限
	int a = 0, b = 1, c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				c = b;
				b = a;
				a = c;
			}
		}
	}
	printf("%d %d", a, b);
	return 0;
}
