#include <stdio.h>
//如果原字符串不要了 
char *substr(char *s,int begin,int end){
	s[end+1]='\0';
	return &s[begin];
}
int main(){
	char a[20]="123456789";
	char *b=substr(a,0,4);
	printf("%s",b);
	return 0;
}
