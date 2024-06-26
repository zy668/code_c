#include<stdio.h>
int main(){
	long long a;
	scanf("%lld",&a);
	long long b=0,c;
	c=a;
	while(c){
		b=b*10+c%10;
		c/=10;
	}
	if(b==a){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
} 
