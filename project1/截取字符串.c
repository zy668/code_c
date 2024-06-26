#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* substr(int begin,int end,char *s){
	char *p=(char *)malloc((end-begin)*sizeof(char));
	int i;
	for(i=0;i<=end-begin;i++){
		p[i]=s[begin+i];
	}
	return p;
}
int main(){
	char ch[50]="hello,world,thank you very much";
	char *b=substr(0,4,ch);
	printf("%s",b);
	return 0;
}
