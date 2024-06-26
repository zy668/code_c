#include <stdio.h>
int main(void){
	int a=0;
	float b,c;
	scanf("%f",&b);
	while (b>=0){
		scanf("%f",&b);
		if(b>=0){
		a++; c=c+b;}
	}
	printf("ave=%f",c/a);
	return 0;
}
