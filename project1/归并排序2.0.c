#include <stdio.h>
#include <stdlib.h>
void mergesort(int a[],int n){
	int left,mid,right,len;
	int *temp=malloc(sizeof(int)*n);
	for(len=1;len<n;len*=2){
		left=0;
		while(left+len<n){
			mid=left+len-1;
			right=mid+len<n?mid+len:n-1;
			int i=left,j=mid+1,k=0;
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
			for(i=left,k=0;k<right-left+1;i++,k++){
				a[i]=temp[k];
			}
			left+=len*2;
		}
	}
	free(temp);
}
int main(){
	int a[10],i;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,10);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
} 
