#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a=1,b=1;
	while(a<=n){while(b<=a){
		printf("%d*%d=%d\t",b,a,a*b);
		if(b==a&&a!=n){printf("\n");break;
		}
		b++;
		}b=1;
		a++;
	}
	return 0;
}
