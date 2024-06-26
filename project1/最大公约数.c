#include <stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	for (c=1;c<=a&&c<=b;c++){
		if(a%c==0){
			if(b%c==0){
				d=c;	
			}
			
		}
		
	}printf("最大公约数为%d",d);
	return 0;
}
