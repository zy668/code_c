#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  for (int i = 31; i >= 0;i--){
    printf("%d", (n & (1 << i))==0?0:1);
  }
    return 0;
}