#include<stdio.h>
#include <string.h>
void get_nextval(char *a,int *nextval){
	int i=1,j=0;
	nextval[1]=0;
	while(i<strlen(a)){
		if(j==0||a[i-1]==a[j-1]){
			i++;
			j++;
            if(a[i-1]!=a[j-1]){
			nextval[i]=j;
            }
            else{
                nextval[i]=nextval[j];
            }
		}
		else{
			j=nextval[j];
		}
	}
}
int main(){
	char *a="adabbadada";
	int nextval[12] = {};
	get_nextval(a, nextval);
	for (int i = 0; i < 12;i++){
		printf("%d ", nextval[i]);
	}
		return 0;
}