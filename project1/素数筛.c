#include <stdio.h>
#include <stdbool.h>
bool a[1000000000]={0};
int main(){
	int n,i=2,j,k;
	scanf("%d",&n);
	while(i<=n){
		if(a[i]==0){
			printf("%d ",i);
		}
		for(j=1;j*i<=n;j++){
			a[i*j]=1;
		}
		while(a[i]!=0){
			i++;
		}
	}
	return 0;
} 
