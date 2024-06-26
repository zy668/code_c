#include <stdio.h>
int main(){
  int a[10] = {1, 3, 8, 4, 2, 9, 6, 5, 0, 7};
  int i, j;
  for (i = 1; i < 10;i++){
    int temp = a[i];
    for (j = i - 1; j >= 0;j--){
      if(a[j]>temp){
        a[j + 1] = a[j];
      }else{
        break;
      }
    }
    a[j + 1] = temp;
  }
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", a[i]);
  }
  
    return 0;
}