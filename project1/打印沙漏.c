#include <stdio.h>
int main(){
	int n,i,b,j,t;
	scanf("%d",&t);
	n=t-1;
	    for(i=1;t>=1;t--,i++){
    	b=2*t-1;
    	j=i;
    while(j>0){
    	printf(" ");
    	j--;
		}
    for(;b>=1;b--){
    printf("*");
    if(b==1){
    	printf("\n");
	}
	}
}
	for(i=2;n>=1;n--,i++){
        b=2*i-1;
		j=n;
	while(j>0){
		printf(" ");
		j--;
	}
	for(;b>=1;b--){
	printf("*");
	if(b==1&&n!=1){
		printf("\n");
	}
	}
}

	return 0;
}
