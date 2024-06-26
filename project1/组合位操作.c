#include <stdio.h>
void combination(int a[],int n,int r){
	int i,j;
	for(i=0;i<(1<<n);i++){
		int count=0;
		for(j=0;j<n;j++){
			if(i&(1<<j)){
				count++;
			}
		}
		if(count==r){
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					printf("%d ",a[j]);
				}
			}
			putchar('\n');
		}
	}
}
int main(){
	int a[6]={1,2,3};
	combination(a,3,2);
	return 0;
} 
