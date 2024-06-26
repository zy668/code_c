#include <stdio.h>
int main(){
	int a[10];
	int i,j,k=1,c;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<9;i++){
		c=1;
		for(j=i+1;j<10;j++){
			if(a[i]==a[j]){
				c=0;
				break;
			}
		}
		if(c==1){
			k++;
		}
	}
	printf("%d",k);
	return 0;
}
