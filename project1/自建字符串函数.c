#include <stdio.h>
int mystrcmp(char* a,char *b){
	int i;
	for(i=0;i<mystrlen(a)&&i<mystrlen(b);i++){
		if(a[i]>b[i]){
			return 1;
		}
		if(a[i]<b[i]){
			return -1;
		}
	}
	if(mystrlen(a)>mystrlen(b)){
		return 1;
	}
	if(mystrlen(a)==mystrlen(b)){
		return 0;
	}
	if(mystrlen(a)<mystrlen(b)){
		return -1;
	}
}
void mystrcpy(char *a,char* b){
	int i;
	for(i=0;i<=mystrlen(b);i++){
		a[i]=b[i];
	}
}
int mystrlen(char a[]){
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	return i;
}
char* mystrchr(char*a,char b){
	int i;
	for(i=0;i<mystrlen(a);i++){
		if(a[i]==b){
			return &a[i];
		}
	}
	return NULL;
}
char * mystrcat(char*a,char*b){
	int i,j;
	for(i=mystrlen(a),j=0;i<=mystrlen(a)+mystrlen(b);i++,j++){
		a[i]=b[j];
	}
}
char * mystrstr(char a[],char b[]){
	int i,j,k;
	if(mystrlen(b)>mystrlen(a)){
		return NULL;
	}
	if(mystrlen(a)==mystrlen(b)){
		for(i=0;i<mystrlen(a);i++){
			if(a[i]!=b[i]){
				return NULL;
			}
		}
		return &a[0];
	}
	if(mystrlen(a)>mystrlen(b)){
		for(i=0;i<=mystrlen(a)-mystrlen(b);i++){
			if(a[i]==b[0]){
				k=1;
				for(j=1;j<mystrlen(b);j++){
					if(a[i+j]!=b[j]){
						k=0;
						break;
					}
				}
				if(k==1){
					return &a[i];
				}
			}
	}
		return NULL;
	}
}
int main(){
	char ch[50]="helheworldlle";
	char a[50]="lle";
//	mystrcpy(a,ch);
	int len=mystrlen(ch);
	char *p=mystrchr(ch,'a');
	char *t=mystrstr(ch,a);
	printf("%d",t-ch);
	return 0;
}
