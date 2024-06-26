#include <stdio.h>
int main(){
	int a,b;
	for(a=2;a<=3000;a++){
	int c=1;
	for(b=2;b<a;b++){
		if(a%b==0){c=0;break;
		}
	}if(c==1){printf("%d ",a);
	}
	
}return 0;
	
}
