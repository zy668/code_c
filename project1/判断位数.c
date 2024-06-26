#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int b=0;
	while(a){
		a/=10;
		b++;
	}
	printf("%d",b);
	return 0;
}
