#include <stdio.h>
int main(){
	int a[100]={1};
	int b;
	scanf("%d",&b);
	int i,c;
	for(i=1;i<=b;i++){
		for(c=0;c<50;c++){
			a[c]*=i;
		}
		for(c=0;c<49;c++){
			if(a[c]>=10){
				a[c+1]+=a[c]/10;
				a[c]%=10;
			}
		}
	}
	int e=49;
	while(a[e]==0){
		e--;
	}
	while(e>=0){
		printf("%d",a[e]);
		e--;
	}
	//long long a[15]
	return 0;
}
