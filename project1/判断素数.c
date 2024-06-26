#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int b,c;
	for(b=2;b<a;b++){
		c=1;
		if(a%b==0){c=0;
			break;
			
		}
		
	}if(c==0){printf("不是素数");
			}
			else{printf("是素数"); 
			} 
	return 0;
}
