#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int b=1;
	while(a>0){b=b*a;a--;
	}printf("%d",b);
	return 0;
}
