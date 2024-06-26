#include <stdio.h>
int isMatch(const char *src, const char *pattern)
{
    if (*pattern == '*') {
    while (*src != '\0') {
        if (isMatch(src, pattern + 1)) {
            return 1;
        }
        src++;
    }
    return isMatch(src, pattern + 1);
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
  printf("%d\n", isMatch("acb.txt", "a?b.txt"));  // 输出1 (true)
  printf("%d\n", isMatch("assssaaaasaa.txt", "a*a"));     // 输出1 (true)
  printf("%d\n", isMatch("cdb.txt", "a*.txt"));  // 输出1 (true)
  printf("%d\n", isMatch("acdb.txt", "a?b.txt")); // 输出0 (false)
  printf("%d\n", isMatch("adaspaspa", "*pa"));
  return 0;
}