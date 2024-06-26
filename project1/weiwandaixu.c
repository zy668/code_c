#include <stdio.h>
#include <string.h>
int main(){
	int ch,i,m,d,j;
	int a[10001]={0},b[10001]={0},c[10001]={0};
		for(i=0;i<10001;i++){
		ch=getchar();
		if(ch=='\n'){
			break;
		}
		a[i]=ch-'0';
	}
	d=i;j=i;
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
		a[i]=ch-'0';
	}
	d=i;
		for(m=10000;m>=10001-d;m--,i--){
		c[m]=a[i-1];
	}
		for(i=0;i<d;i++){
		a[i]=0;
	}
	if(j>d){
	for(m=10000;m>=10001-d;m--){
		a[m]=b[m]-c[m];
		if(a[m]<0){
			a[m-1]-=1;
			a[m]+=10;
		}
		}
	}
	if(j<=d){
		for(m=10000;m>=10001-d;m--){
		a[m]=b[m]-c[m];
		if(a[m]<0){
		
		}
		}
	}
	for(i=0;i<10001;i++){
		if(a[i]!=0){
			break;
		}
		if(i==10001){
			printf("0");
		}
	}
	for(;i<10001;i++){
		printf("%d",a[i]);
	}
	return 0;
}
