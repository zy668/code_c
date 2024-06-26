#include <stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int a=i;
		for(;a>0;a--){
			printf("$");
			if(a==1){
				printf("\n");
			}
		}
	}
	return 0;
}
