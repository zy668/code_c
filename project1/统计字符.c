#include <stdio.h>
int main(){
	int i=0,j=0,k=0,p=0;
	char a;
	do{
	scanf("%c",&a);
	if('a'<=a&&a<='z'||'A'<=a&&a<='Z'){
		i++;
	}
	else if(a==' '){
		j++;
	}
	else if('0'<=a&&a<='9'){
		k++;
	}
	else{
		p++;
	}
}while(a!='\n');
printf("%d %d %d %d",i,j,k,p-1);
return 0;
}
