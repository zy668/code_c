#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void two_quicksort(int *a,int l,int r){
	if(l>=r) return;
	int i=l,j=r,key=a[l],temp;
	while(i<=j){
		while(a[i]<key) i++;
		while(a[j]>key) j--;
		if(i<=j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	for (int i = 0; i < 10;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	two_quicksort(a, l, j);
	two_quicksort(a,i,r);
}
void tri_quicksort(int *a,int l,int r){
	if(l>=r) return;
	int i=l,j=r,key=a[l+rand()%(r-l+1)],temp;
	int k=l;
	while(k<=j){
		if(a[k]<key){
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
			i++;
			k++;
		}
		else if(a[k]>key){
			temp=a[k];
			a[k]=a[j];
			a[j]=temp;
			j--;
		}
		else{
			k++;
		}
	}
	tri_quicksort(a,l,i-1);
	tri_quicksort(a,j+1,r);
}
int main(){
	srand(time(NULL));
	int a[10] = {503, 87, 512, 61, 908, 170, 897, 275, 653, 426};
	int i;
	// for(i=0;i<10;i++){
	// 	scanf("%d",&a[i]);
	//
	two_quicksort(a, 0, 9);
	// tri_quicksort(a,0,19);
	// for(i=0;i<20;i++){
	// 	printf(" %d"+!i,a[i]);
	// }
	return 0;
}
