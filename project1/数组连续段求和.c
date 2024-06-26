#include<stdio.h>
int main(){
	int a[1000]={0};
	int b[1000]={0};
	int i,j,k,n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-m;i++){
		for(j=i;j<m+i;j++){
			b[i]+=a[j];
		}
	}
	for(i=0;i<=n-m;i++){
		printf("%d",b[i]);
	}
	return 0;
} 
