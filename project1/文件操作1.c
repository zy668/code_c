#include<stdio.h>
int main(){
	FILE *pf=fopen("test.txt","r");
	if(pf==NULL){
		printf("文件不存在");
	}
	else{
		char ch;
		while((ch=getc(pf))!=EOF){
			printf("%c",ch);
		}
	}
	fclose(pf);
	return 0;
}
