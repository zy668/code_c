#include <stdio.h>
int main(){
	int a[10];
	int i=0;
	while(i<10){
		scanf("%d",&a[i]);
		i++;
	}
	int j=1,c=1;
	int d,b;
	for(i=0;i<10;i++){
		j=i+1;
		while(j<10){
			if(a[i]==a[j]){
				c++;
			}j++;
		}
		d=0;if(d<c){
			d=c; b=a[i];
		}
	}printf("ÖÚÊýÊÇ%d",b);
	return 0;
} 
