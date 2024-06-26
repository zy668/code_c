#include<stdio.h>
int main(){
	int i,n,p;
	int a[10000]={2};
	int t=0;
	scanf("%d",&n);
	for(p=3;p<=n;p++){
		i=0;
		for(;a[i]!=0;i++){
			if(p%a[i]==0){
				break;
			}
			if(p%a[i]!=0&&i==t){
				a[i+1]=p;
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
