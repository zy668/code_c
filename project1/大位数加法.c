#include <stdio.h>
int main(){
	int ch,i,m,d;
	char ch1[10001]={'0'};
	char ch2[10001]={'0'};
	int a[10001]={0},b[10001]={0},c[10001]={0};
		for(i=0;i<10001;i++){
		ch=getchar();
		if(ch=='\n'){
			break;
		}
		ch1[i]=ch;
		a[i]=ch-'0';
	}
	d=i;
	for(m=10000;m>=10001-d;m--,i--){
		b[m]=a[i-1];
	}
	for(i=0;i<d;i++){
		a[i]=0;
	}
			for(i=0;i<10001;i++){
		ch=getchar();
		if(ch=='\n'){
			break;
		}
		ch2[i]=ch;
		a[i]=ch-'0';
	}
	d=i;
		for(m=10000;m>=10001-d;m--,i--){
		c[m]=a[i-1];
	}
		for(i=0;i<d;i++){
		a[i]=0;
	}
	for(i=0;i<10001;i++){
		if(b[i]!=0||c[i]!=0){
			break;
		}
		if(i==10000){
			printf("0");
		}
	}
	d=i;
	for(i=10000;i>=d-1;i--){
		a[i]=b[i]+c[i];
		if(a[i]>=10){
			b[i-1]+=1;
			a[i]%=10;
		}
	}
	if(a[d-1]!=0){
		printf("%d",a[d-1]);
	}
	for(i=d;i<10001;i++){
		printf("%d",a[i]);
	}
	return 0;
}
