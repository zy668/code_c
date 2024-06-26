#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int c=0;
	while(a>0){
		int d=a%10;
		if(d==b){
			c++;
		}
		a/=10;
	}
	printf("%d\n",c);
	int e=b;
	while(c>1){
		b=b*10+e;
		c--;
	}printf("%d",b);
	return 0;
} 
