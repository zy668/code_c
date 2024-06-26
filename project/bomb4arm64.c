#include <stdio.h>
int func4(int w0, int w1)
{
  if (w0 <= 0)
  {
    return 0;
  }
  if (w0 == 1)
  {
    return w1;
  }

  int value1 = func4(w0 - 1, w1);
  int value2 = func4(w0 - 2, w1);
  return value1 + value2 +w1;
}
int main()
{
  for (int i = 0; i < 5;i++){
    printf("%d %d\n", i, func4(9, i));
  }
    return 0;
}