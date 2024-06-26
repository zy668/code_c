#include <stdio.h>
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=6;i<=n;i++){
		k=0;
		for(j=1;j<=i/2;j++){
			if(i%j==0){
				k+=j;
			}
		}
		if(k==i){
			printf("%d\n",i);
		}
	}
	return 0;
}
