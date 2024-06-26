#include <stdio.h>
int main(){
	int a,b,c,d,count=0;
	for(a=0;a<=17;a++){
		for(b=0;b<=17;b++){
			for(c=0;c<=17;c++){
				for(d=0;d<=17;d++){
					if(a+b+c+d==17){
						printf("%d %d %d %d\n",a,b,c,d);
						count++;
					}
				}
			}
		}
	}
	printf("%d",count);
	return 0;
} 
