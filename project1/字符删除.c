#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char * exclude(char *a,char ch){
	char *b=malloc(sizeof(char)*(strlen(a)+1));
	int i,j;
	for(i=0,j=0;i<strlen(a);i++){
		if(a[i]!=ch){
			b[j++]=a[i];
		}
	}
	b[j]='\0';
	return b;
}
int main(){
	int n;
	char a[20]="123455";
	char *b=exclude(a,'2');
	printf("%s",b);
	free(b);
	b=NULL;
	return 0;
}
