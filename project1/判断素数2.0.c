#include <stdio.h>
#include <math.h>
int main(){
	int a,d;
	scanf("%d",&a);
	int c=1;
	int b=sqrt(a)+1;
	for(d=2;d<=b&&d<a;d++){
		if(a%d==0){
			c=0;break;
		}
	}
	if(c==0){
		printf("不是素数");
	}
	else{
		printf("是素数");
	} 
	return 0;
}
