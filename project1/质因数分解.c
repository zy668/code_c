#include<stdio.h>
#include <math.h>
int main(){
	int q;
	scanf("%d",&q);
	int b=sqrt(q);
	int i,n,p;
	int a[10000]={2,3};
	int t=1;
	n=q;
	for(p=4;p<=n;p++){
		i=0;
		for(;sqrt(p)>a[i];i++){
			if(p%a[i]==0){
				break;
			}
			if(p%a[i]!=0&&sqrt(p)<a[i+1]){
				a[t+1]=p;
				t++; 
				break;
			}
		}
}
while(q>1){
	for(i=0;i<=t;i++){
		if(q%a[i]==0){
			printf("%d ",a[i]);
			q/=a[i];
		}
	}
}
	return 0;
} 
