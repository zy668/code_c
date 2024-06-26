#include <stdio.h>
int main(){
	int a1,a2,a3;
	a1=a2=1;
	int n;
	scanf("%d",&n);
	while(n>2){
		n--;
		a3=a1;
		a1=a2;
		a2=a1+a3;
	}
	printf("%d",a2);
	return 0;
} 
