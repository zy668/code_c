#include <stdio.h>
void quicksort(int a[],int l,int r){
	if(l>=r) return;
	int i=l,j=r,k=a[(l+r)/2],temp;
	while(i<=j){
		while(a[i]<k) i++;
		while(a[j]>k) j--;
		if(i<=j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	quicksort(a,l,j);
	quicksort(a,i,r);
}
int main(){
	int a[10]={1,2,3,6,5,4,8,7,0,9};
	quicksort(a,0,9);
	int i;
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
