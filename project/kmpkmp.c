#include <stdio.h>
#include <string.h>
void get_next(char *a,int *next){
	int i=1,j=0;
	next[1]=0;
	while(i<strlen(a)){
		if(j==0||a[i-1]==a[j-1]){
			i++;
			j++;
			next[i]=j;
		}
		else{
			j=next[j];
		}
	}
}
int kmp(char *s,char *t){
	int next[10]={0};
	int i=1,j=1;
	get_next(t,next);
	while(i<=strlen(s)&&j<=strlen(t)){
		if(j==0||s[i-1]==t[j-1]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>strlen(t)){
		return i-strlen(t);
	}
	return -1;
}
int main(){
	// int i=kmp("ababcabcacbab","abcac");
	// printf("%d",i);
	char s[] = "abaaabaabbac";
	int next[13] = {};
	get_next(s, next);
	for (int i = 0; i < 13;i++){
		printf("%d ", next[i]);
	}
		return 0;
}
