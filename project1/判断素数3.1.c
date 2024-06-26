#include<stdio.h>
#include <math.h>
int main(){
	int i,n,p;
	int a[10000]={2,3};
	int t=1;
	scanf("%d",&n);
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
if(a[t]!=n){
	printf("不是素数");
}
else{
	printf("是素数"); 
}
	return 0;
} 
