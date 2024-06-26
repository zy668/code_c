#include <stdio.h>
#include <stdlib.h> 
int  cmp(const void* a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int a[10];
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,10,4,cmp);
	for(i=0;i<10;i++){
		printf(" %d"+!i,a[i]);
	}
	return 0;
}
