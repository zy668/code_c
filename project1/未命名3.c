#include <stdio.h>
void bubblesort(int a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int k=1;
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				k=0;
			}
		}
		if(k){
			break;
		}
	}
}
int main(){
	int a[6]={3,5,7,1,2,8};
	bubblesort(a,6);
	int i;
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
