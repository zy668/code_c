#include <stdio.h>
#include <math.h>
int main(){
	int a,b;
	int n;
	scanf("%d",&n);
	for(a=2;a<=n;a++){
	int d=sqrt(a)+1;
	int c=1;
	for(b=2;b<=d&&b<a;b++){
		if(a%b==0){
			c=0;break;
		}
	}if(c==1){
		printf("%d ",a);
	}
}
return 0;
}
