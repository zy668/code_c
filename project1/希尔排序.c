#include <stdio.h>
void shellsort(int *a,int n){
	int step=n/2;
	int i,j,temp;
	for(step=n/2;step>0;step/=2){
		for(i=step;i<n;i++){
			temp=a[i];;
			j=i-step;
			while(j>=0&&temp<a[j]){
				a[j+step]=a[j];
				j-=step;
			}
			a[j+step]=temp;
		}
	}
}
int main(){
	int i;
	int a[10]={0};
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	shellsort(a,10);
	for(i=0;i<10;i++){
		printf(" %d"+!i,a[i]);
	}
	return 0;
} 
