#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void print(void){
  bool *b = (bool *)malloc(10 * sizeof(bool));
  for (int i = 0; i < 10;i++){
    printf("%d ", b[i]);
  }
}
int main(){
  print();
  return 0;
}