#include <stdio.h>
#include <string.h>
int main(){
	int ch,i,d,len1,len2;
	int a[10001]={0},b[10001]={0};
	char ch1[10001],ch2[10001];
	for(i=0;i<10001;i++){
		ch=getchar();
		if(ch=='\n'){
			break;
		}
		ch1[i]=ch;
	}
	len1=strlen(ch1);
	d=len1;
	for(i=10000;i>=10001-len1;i--,d--){
		a[i]=ch1[d-1]-'0';
	}
	for(i=0;i<10001;i++){
		ch=getchar();
		if(ch=='\n'){
			break;
		}
		ch2[i]=ch;
	}
	len2=strlen(ch2);
	d=len2;
	for(i=10000;i>=10001-len2;i--,d--){
		b[i]=ch2[d-1]-'0';
	}
if(strcmp(ch1,ch2)>=0){
	for(i=10000;i>=10001-len1;i--){
		a[i]=a[i]-b[i];
		if(a[i]<0){
			a[i-1]-=1;
			a[i]+=10;
		}
	}
}
if(strcmp(ch1,ch2)<0){
		for(i=10000;i>=10001-len2;i--){
		a[i]=b[i]-a[i];
		if(a[i]<0){
			b[i-1]-=1;
			a[i]+=10;
		}
	}
}
for(i=0;i<10001;i++){
	if(a[i]!=0){
		break;
	}
	if(i==10000){
		printf("0");
	}
}
if(strcmp(ch1,ch2)<0){
	printf("%d",-a[i]);
	i++;
}
for(;i<10001;i++){
	printf("%d",a[i]);
}
	return 0;
}
