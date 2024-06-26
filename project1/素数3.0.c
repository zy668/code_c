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
	for(i=0;i<=t;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
