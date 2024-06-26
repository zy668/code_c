#include<stdio.h>
int main(){
	char *p="12345";
	char s[]="12345";
	char *p1="12345";
	char s1[]="12345";
	s[2]='6';
	printf("%s",s);
	//printf("%p\n%p\n",p,s);
	//printf("%p\n%p",p1,s1);
	return 0;
}
