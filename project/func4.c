#include <stdio.h>
int func4(int edi, int esi, int edx)
{
  int eax = edx - esi;
  eax += (eax >> 31);
  eax /= 2;
  int ecx = eax + esi;

  if (ecx <= edi)
  {
    if (ecx == edi)
    {
      return 0;
    }
    else
    {
      return 2 * func4(edi, ecx + 1, edx) + 1;
    }
  }
  else
  {
    return 2 * func4(edi, esi, ecx - 1);
  }
}
int main()
{
  for (int i = 0; i < 14; i++)
  {
    printf("num1:%d %d\n", i, func4(i, 0, 14));
  }
  return 0;
}