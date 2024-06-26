#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct arrayQueue{
	int ele[N];
	int front;
	int rear;
	int size;
}queue;
void pushback(queue *a,int n){
	if(a->size==N){
		printf("FULL");
	}
	else{
		a->ele[a->rear%N]=n;
		a->rear++;
		a->size++;
	}
}
void popfront(queue *a){
	if(a->size==0){
		printf("Empty");
	}
	else{
		a->front++;
		a->front%=N;
		a->size--;
	}
}
int main(){
	int n;
	queue a;
	a.front=a.rear=0;
	a.size=0;
	scanf("%d",&n);
	while(n!=-1){
		pushback(&a,n);
		scanf("%d",&n);
		if(a.size==N){
			break;
		}
	}
	popfront(&a);
	popfront(&a);
		while(n!=-1){
		pushback(&a,n);
		scanf("%d",&n);
		if(a.size==N){
			break;
		}
	}
	while(a.size){
		printf("%d ",a.ele[a.front]);
		popfront(&a);
	}
	return 0;
}
