#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool a[100000000]={0};
int main(){
	int n,i=2,j,k;
	n=100000000;
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
