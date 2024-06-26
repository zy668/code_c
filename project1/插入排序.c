#include <stdio.h>
int main(){
	int i,j,k;
	int a[10]={0};
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<10;i++){
		k=a[i];
		for(j=i-1;j>=0&&a[j]>k;j--){
			a[j+1]=a[j];
		}
		a[j+1]=k;
	}
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
