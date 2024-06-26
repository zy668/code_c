#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b<=c||a+c<=b||b+c<=a){
		printf("The edges cannot make up of a triangle.");
	}
	else{
		double d=(a+b+c)/2.0;
		double s=sqrt(d*(d-a)*(d-b)*(d-c));
		printf("%.3lf",s);
	}
	return 0;
}
