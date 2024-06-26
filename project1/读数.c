#include <stdio.h>
void num(int f){
	switch(f){
    case 0:printf("ling");break;
    case 1:printf("yi");break;
    case 2:printf("er");break;
    case 3:printf("san");break;
    case 4:printf("si");break;
    case 5:printf("wu");break;
    case 6:printf("liu");break;
    case 7:printf("qi");break;
    case 8:printf("ba");break;
    case 9:printf("jiu");break;
    }
}
int main(){
    long long t;
	scanf("ll%d",&t);
    int b=0;
	while(t>0){
        b+=t%10;
        t/=10;
    }
	int e=b;
	int a=0;
	while(b>9){
		a++;
		b/=10;
	}
	int c=1;
	while(a>0){
		c*=10;
		a--;
	}
	int f;
	while(c>0){
		f=e/c;
        num(f);
		e%=c;
		c/=10;
		if(c>0){printf(" ");
		}
	}
	return 0;
}
