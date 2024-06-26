#include <stdio.h>
int main(){
	int b,i,k;
	int a[10];
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(k=0;k<9;k++){
		int c=0;
		for(i=0;i<9-k;i++){
		if(a[i]>a[i+1]){
			b=a[i];
			a[i]=a[i+1];
			a[i+1]=b;
			c=1;
		}
	}		
	if(c==0){
			break;
		}
}
for(i=0;i<10;i++){
	printf("%d",a[i]);
}
	return 0;
}
