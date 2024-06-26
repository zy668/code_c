#include <stdio.h>
#include <string.h>
int main(){
	char a[2001]="";
	char b[2001]="";
	char c[4002]="";
	scanf("%s %s",a,b);
	int i,j,k,x=0,y=0;
//	if(a[0]=='-'&&b[0]=='-'){
//		x=1;
//		y=1;
//	}
//	else if(a[0]=='-') x=1;
//	else if(b[0]=='-') y=1;
	int lena=strlen(a);
	int lenb=strlen(b);
	for(i=lena-1;i>=x;i--){
		for(j=lenb-1;j>=y;j--){
			k=(a[i]-'0')*(b[j]-'0');
			c[i+j+1]+=k%10;
			c[i+j]+=k/10;
		}
	}
	for(i=lena+lenb-1;i>x+y;i--){
		c[i-1]+=c[i]/10;
		c[i]=c[i]%10+'0';
	}
	c[i]+='0';
//	if((x+y)%2) putchar('-');
	if(c[i]=='0') printf("%s",&c[i+1]);
	else printf("%s",&c[i]);
	return 0;
}
