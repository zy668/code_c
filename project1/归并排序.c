#include <stdio.h>
#include <stdlib.h>
void mergesort(int a[],int left,int right){
	if(left>=right) return;
	int mid=(right+left)/2;
	mergesort(a,left,mid);
	mergesort(a,mid+1,right);
	int i=left,j=mid+1,k=0;
	int *temp=malloc(sizeof(int)*(right-left+1));
	while(i<=mid&&j<=right){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid) temp[k++]=a[i++];
	while(j<=right) temp[k++]=a[j++];
	for(i=left,k=0;i<=right;i++,k++){
		a[i]=temp[k];
	}
	free(temp);
}
int main(){
	int a[10];
	int i,j;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,0,9);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
} 
