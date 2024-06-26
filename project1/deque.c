#include <stdio.h>
#define maxsize 100
typedef struct deque{
	int ele[maxsize];
	int front;
	int rear;
	int size;
}deque;
void init(deque *q){
	q->front=0;
	q->rear=0;
	q->size=0;
}
void pushback(deque *q,int val){
	if(q->size==maxsize){
		printf("FULL");
		return;
	}
	q->ele[q->rear++]=val;
	q->rear%=maxsize;
	q->size++;
}
void pushfront(deque *q,int val){
	if(q->size==maxsize){
		printf("FULL");
		return;
	}
	q->ele[q->front--]=val;
	if(q->front<0){
		q->front+=maxsize;
	}
	q->size++;
}
void popback(deque *q){
	if(q->size==0){
		printf("EMPTY");
		return;
	}
	q->ele[q->rear--];
	if(q->rear<0){
		q->rear+=maxsize;
	}
	q->size--;
}
void popfront(deque *q){
	if(q->size==0){
		printf("EMPTY");
		return;
	}
	q->ele[q->front++];
	q->front%=maxsize;
	q->size--;
}
int main(){
	
	return 0;
}
