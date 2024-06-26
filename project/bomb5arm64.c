#include <stdio.h>
int array[16] = {
    10, 2, 14, 7,
    8, 12, 15, 11,
    0, 4, 1, 13,
    3, 9, 6, 5
};
void bomb(void)
{
  printf("bomb!\n");
}
void phase_5(int i)
{
  int num1 = i; //, num2;
  // if (scanf("%d %d", &num1, &num2) < 2)
  // {
  //   bomb();
  // }
  num1 &= 0xf;
  if (num1 == 0xf)
  {
    bomb();
  }
  int count = 0, sum = 0, n = num1;
  do
  {
    count++;
    n = array[n];
    sum += n;
  } while (n != 15);
  if (count != 0xf)
  {
    bomb();
  }
  // if (sum != num2)
  // {
  //   bomb();
  // }
  printf("%d\n",sum);
}

int main()
{
  for (int i = 0; i < 16;i++){
    printf("%d\n", i);
    phase_5(i);
  }
    return 0;
}