#include <stdio.h>
int num(int a,int b) {
	int c;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}return a;
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int c=a*b/num(a,b);
	printf("%d",c);
	return 0;
}
