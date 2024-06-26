#include <stdio.h>
#include <string.h>
int main(){
	int n,i;
	//scanf("%d",&n);
	n=151;
	char ch[10];
	for(i=0;i<10;i++){
		if(n){
		ch[i]=n%10+'0';
		n/=10;
	}
}
printf("%s",ch);
	return 0;
}
