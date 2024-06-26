#include <stdio.h>
int main(){
	int ch;
	int a=0,b=0,c=0,d=0;
	while((ch=getchar())!='\n'){
		if(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')){
			a++;
		}
		else if(ch==' '){
			b++;
		}
		else if('0'<=ch<='9'){
			c++;
		}
		else{
			d++;
		}
	}
	printf("%d %d %d %d",a,b,c,d);
	return 0;
}
