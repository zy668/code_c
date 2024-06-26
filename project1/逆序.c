#include <stdio.h>
int main(){
	int a,b;
	scanf("%d",&a);
	//È¥0Ôò while(a%10==0){a/=10};
	while(a>0){
		b=a%10;
		printf("%d",b);
		a/=10;
	}
	return 0;
}
