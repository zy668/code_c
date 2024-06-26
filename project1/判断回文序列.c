#include<stdio.h>
#include <string.h>
int main(){
	char ch[10000];
	scanf("%s",ch);
	int i;
	int a=strlen(ch);
	int c=1;
	for(i=0;i<a/2;i++){
		if(ch[i]!=ch[a-1-i]){
			c=0;
			break;
		}
	}
	if(c==1){
		printf("Yes");
	}
	else{
		printf("No");
	}
return 0;
}
