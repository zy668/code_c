#include <stdio.h>
int part(int r[], int n)
{
  int temp, low = 0, high = n - 1, k;
  temp = r[0];
  while (low < high)
  {
    while (low < high && r[high] >= temp)
    {
      high--;
    }
    if (low < high)
    {
      r[low] = r[high];
      low++;
    }
    while (low < high && r[low] <= temp)
    {
      low++;
    }
    if (low < high)
    {
      r[high] = r[low];
      high--;
    }
    r[low] = temp;
    return low;
  }
}
void quick(int r[], int n)
{
  int k;
  if (n < 2)
  {
    return;
  }
  k = part(r, n);
  for (int i = 0; i < n;i++){
    printf("%d ", r[i]);
  }
  putchar('\n');
  quick(r, k);
  quick(&r[k + 1], n - (k + 1));
}
int main()
{
  int r[10] = {508, 87, 512, 61, 908, 170, 897, 275, 653, 426};
  quick(r, 10);
  return 0;
}