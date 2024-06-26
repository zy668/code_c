#include <stdio.h>
int main(){
	char ch;
	scanf("%c",&ch);
	int i,j,k;
	int n=ch-'A';
	for(i=0;i<=n;i++){
		j=n-i;
		for(;j>0;j--){
			printf(" ");
		}
		for(k=n;k>=n-i;k--){
			printf("%c",ch-k);
		}
		for(k=n-i;k<=n;k++){
			if('A'<=ch-k-1&&ch-k-1<='Z'){
			printf("%c",ch-k-1);}
			if(k==n){
				printf("\n");
			}
		}
	}
	return 0;
}
