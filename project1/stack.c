#include <stdio.h>
#define size 20
typedef struct arrayStack{
	int ele[size];
	int top;
}stack;
void push(stack *a,int val){
	if(a->top==size-1){
		printf("FULL");
	}
	else{
		a->ele[++a->top]=val;
	}
}
void pop(stack *a){
	if(a->top!=-1){
		a->top--;
	}
	else{
		printf("Empty");
	}
}
int main(){
	stack a;
	a.top=-1;
	printf("%d\n",a.ele[a.top]);
	pop(&a);
	printf("%d\n",a.ele[a.top]);
	pop(&a);
	pop(&a);
	return 0;
}
