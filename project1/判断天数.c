#include <stdio.h>
typedef struct time{
	int y;
	int m;
	int d;
} D;
int main(){
	D a;
	int sum=0;
	scanf("%d %d %d",&a.y,&a.m,&a.d);
	int p[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(a.y%400==0||(a.y%4==0&&a.y%100!=0)){
		p[2]=29;
	}
	int i;
	for(i=0;i<=a.m-1;i++){
		sum+=p[i];
	}
	sum+=a.d;
	printf("%d",sum);
	return 0;
}
