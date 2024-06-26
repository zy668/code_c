#include <stdio.h>
int isMatch(const char *src, const char *pattern)
{
  if (*pattern == '*')
  {
    while (*(pattern + 1) == '*')
    {
      pattern++;
    }
    return isMatch(src, pattern + 1) || ((*src != '\0') && isMatch(src + 1, pattern));
  }
  if (*pattern == '\0')
  {
    return *src == '\0';
  }
  if (*pattern == '?')
  {
    return (*src != '\0') && isMatch(src + 1, pattern + 1);
  }
  return (*src == *pattern) && isMatch(src + 1, pattern + 1);
}
int main()
{
  char src[128] = "";
  char pattern[128] = "";
  printf("please enter filename and then pattern string:\n");
  scanf("%s %s", src, pattern);
  if (isMatch(src,pattern))
  {
    printf("match");
  }
  else
  {
    printf("mismatch");
  }
  return 0;
}