#include <stdio.h>
#include <string.h>
int strrstr(char *a,char *b){
	int lenA=strlen(a);
	int lenB=strlen(b);
	int i,j,k;
	for(i=lenA-lenB;i>=0;i--){
		k=1;
		for(j=0;j<lenB;j++){
			if(a[i+j]!=b[j]){
				k=0;
				break;
			}
		}
		if(k==1){
			return i;
		}
	}
	return -1;
}
int main(){
	char s[60]="ababcdhellocdddwowowollmfayouworld";
	char ch[6]="hel";
	printf("%d",strrstr(s,ch));
	return 0;
} 
