#include<stdio.h>
int main(){
	char s[20]="";
	int ch,j=0;
	while((ch=getchar()!='\n')){
			s[j]=ch;
			j++;
		}
		printf("%s",s);
	return 0;
} 
