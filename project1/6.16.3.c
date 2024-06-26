#include <stdio.h>
int main(){
	char ch;
	scanf("%c",&ch);
	int a=ch-'A';
	int i,b;
	char c=ch;
	for(i=0;i<=a;i++){
		ch=c;
		for(b=i;b>=0;b--){
			printf("%c",ch);
			ch--;
		if(b==0){
			printf("\n");
		}
		}
	}
	return 0;
}
