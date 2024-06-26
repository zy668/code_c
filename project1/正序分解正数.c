#include <stdio.h>
int main(){
	int b,e;
	scanf("%d",&b);
	e=b;
	int a=0;
	while(b>9){
		a++;
		b/=10;
	}
	int c=1;
	while(a>0){
		c*=10;
		a--;
	}
	int f;
	while(c>0){
		f=e/c;
		printf("%d",f);
		e%=c;
		c/=10;
		if(c>0){printf(" ");
		}
	}
	return 0;
}
