#include <stdio.h>
void bomb(void){
  printf("bomb....");
}
void test(){
  int num1, num2;
  if(scanf("%d %d",&num1,&num2)!=2){
    bomb();
  }
  if(num1<10){
    bomb();
  }
  if(num2>30){
    bomb();
  }
}
int main(){
  test();
  return 0;
}