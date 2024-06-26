#include<stdio.h>
int num(int a,int b) {
	int c;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}return a;
}

int main(){
	int a,b;
    scanf("%d/%d",&a,&b);
    int d=num(a,b);
    printf("%d/%d",a/d,b/d);
    return 0;
}
