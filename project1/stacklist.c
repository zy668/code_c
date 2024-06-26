#include <stdio.h>
#include <stdlib.h>
typedef struct listStack{
	int val;
	struct listStack * next;
}stack;
stack * push(stack *a,int n){
	stack *b=malloc(sizeof(stack));
	b->next=a;
	b->val=n;
	return b;
}
stack *pop(stack *a){
	if(a=NULL){
		printf("EMPTY");
		return 0;
	}
	stack *b=a->next;
	free(a);
	a=NULL;
	return b;
}
int size(stack *a){
	int i=0;
	while(a){
		i++;
		a=a->next;
	}
	return i;
}
int main(){
	int n;
	stack *top=NULL;
	scanf("%d",&n);
	while(n!=-1){
		top=push(top,n);
		scanf("%d",&n);
	}
	top=pop(top);
	printf("%d\n",size(top));
	printf("%d",top->val);
	return 0;
}
