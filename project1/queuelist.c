#include <stdio.h>
#include <stdlib.h>
typedef struct listQueue{
	int val;
	struct listQueue* next;
}queue;
queue *pushback(queue *a,int n){
	queue *b=malloc(sizeof(queue));
	a=b;
	b->val=n;
	return b;
}
queue *popfront(queue *a){
	if(a=NULL){
		printf("EMPTY");
		return 0;
	}
	queue *b=a->next;
	free(a);
	a=NULL;
	return b;
}
int main(){
	int n;
	queue *front=NULL;
	queue *rear=NULL;
	scanf("%d",&n);
	while(n!=-1){
	if(front){
		rear=pushback(rear,n);
	}
	else{
		front=pushback(front,n);
		rear=front;
	}
		scanf("%d",&n);
	}
	printf("%d",front->val);
	return 0;
}
