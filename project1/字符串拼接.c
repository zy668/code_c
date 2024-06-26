#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char * append(char *a,char *b){
	int len=strlen(a)+strlen(b)+1;
	char *c=malloc(sizeof(char)*len);
	strcpy(c,a);
	strcpy(&c[strlen(a)],b);
	return c;
}
int main(){
	char *a="hello";
	char *b=",world";
	char *c=append(a,b);
	printf("%s",c);
	free(c);
	c=NULL;
	return 0;
}
