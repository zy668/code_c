#include <stdio.h>
#include <ctype.h>
#include <string.h>
void copy(char a[], char b[])
{
  int i = 0, j = 0;
  while (a[i] != '\0')
  {
    if (isalpha(a[i]))
    {
      b[j++] = tolower(a[i]);
    }
    i++;
  }
  b[j] = '\0';
}
int isPalindrome(char b[])
{
  int n = strlen(b);
  for (int i = 0; i < n / 2; i++)
  {
    if (b[i] != b[n - i - 1])
    {
      return 0;
    }
  }
  return 1;
}
int main()
{
  char a[35] = "A Man, a Plan, a Canal: Panama!";
  char b[35] = "";
  copy(a, b);
  printf("%s\n", b);
  printf("%d", isPalindrome(b));
}