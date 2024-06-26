#include <stdio.h>
#include <stdlib.h> 
void print_combination(int a[],int b[],int start,int end,int index,int r){
	int i;
	if(index==r){
		for(i=0;i<r;i++){
			printf("%d ",b[i]);
		}
		putchar('\n');
		return;
	}
	for(i=start;i<=end&&end-i+1>=r-index;i++){
		b[index]=a[i];
		print_combination(a,b,i+1,end,index+1,r);
	}
}
void find_combination(int a[],int n,int r){
	int *b=malloc(sizeof(int)*r);
	print_combination(a,b,0,n-1,0,r);
	free(b);
}
int main(){
	int a[6]={1,2,3,4,5,6};
	find_combination(a,6,3);
	return 0;
} 
