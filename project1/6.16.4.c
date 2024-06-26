#include <stdio.h>
int main(){
	char ch='A';
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		int a=i;
		for(;a>0;a--){
		printf("%c",ch++);
		if(a==1){
			printf("\n");
		}
	}
	}
	return 0;
}
