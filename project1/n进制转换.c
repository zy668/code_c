#include <stdio.h>
int main(){
	int a,n;
	scanf("%d %d",&a,&n);
	int e=a;
	int i=0,d=1; 
	while(a/n){
		a/=n;
		d*=a;
	}
    int c=0;
    while(d>0){
    	c=c*10+e/d;
    	e-=e/d*d;
    	d/=n;
	}
	printf("%d",c);
	return 0;
}
