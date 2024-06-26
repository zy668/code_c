#include <stdio.h>
#define maxsize 20
typedef struct stack{
	int ele[maxsize];
	int top;
	int size;
}stack;
void init(stack *s){
	s->size=0;
	s->top=0;
}
void push(stack *s,int val){
	if(s->size==maxsize) printf("FULL");
	else{
		s->ele[++s->top]=val;
		s->top%=maxsize;
		s->size++;
	}
}
int pop(stack *s){
	if(s->size==0){
		printf("Empty");
		return -1;
	}
	int t=s->ele[s->top];
	s->top--;
	s->size--;
	if(s->top<0) s->top+=maxsize;
	return t;
}
int main(){
	stack a;
	init(&a);
	push(&a,2);
	push(&a,3);
	printf("%d\n",a.ele[a.top]);
	pop(&a);
	printf("%d\n",a.ele[a.top]);
	pop(&a);
	pop(&a);
	return 0;
}
