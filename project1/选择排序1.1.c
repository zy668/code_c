#include<stdio.h>
int main(){
	int a[10]={0};
	int i,j,min,k;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<9;i++){
		min=a[i];k=i;
		for(j=i+1;j<10;j++){
			if(min>a[j]){
				k=j;
				min=a[j];
			}
		}
		a[k]=a[i];
		a[i]=min;
	}
	for(i=0;i<10;i++){
		printf(" %d"+!i,a[i]);
	}
	return 0;
} 
