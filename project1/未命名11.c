#include <stdio.h>
#include <string.h>
int check(char *ch,int a){
	int i,c=1;
	for(i=0;i<a/2;i++){
		if(ch[i]!=ch[a-1-i]){
			c=0;
			break;
		}
	}
	return c;
}
int main(){
	int a[1000][26]={0};
	char s[201]={""};
	int n,i,ch,j,k,t;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		j=0;
		while((ch=getchar())!='\n'){
			a[i][ch-'a']+=2;
			s[j]=s[j+1]=ch;
			j+=2;
		}
		if(!check(s,j-2)){
			for(k=0;k<26;k++){
				if(a[i][k]){
					for(t=0;t<a[i][k]/2;t++){
						putchar('a'+k);
					}
				}
			}
			for(k=25;k>=0;k--){
				if(a[i][k]){
					for(t=0;t<a[i][k]/2;t++){
						putchar('a'+k);
					}
				}
			}
			putchar('\n');
		}
		else{
			printf("%s\n",s);
		}
	}
	return 0;
}
