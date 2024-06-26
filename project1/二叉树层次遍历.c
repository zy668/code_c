#include <stdio.h>
#include <stdlib.h>
#define maxsize 64
typedef struct bintree{
	int data;
	struct bintree *left,*right;
}node;
typedef struct arrayQueue{
	node * q[maxsize];
	int rear;
	int front;
	int size;
}queue;
int push(queue* a,node *b){
	if(a->size==maxsize){
		printf("FULL");
		return 0;
	}
	a->q[a->rear++]=b;
	if(a->size>maxsize){
		a->size%=maxsize;
	}
	a->size++;
	return 1;
}
node* pop(queue *a){
	if(a->size==0){
		printf("EMPTY");
		return NULL;
	}
	a->size--;
	if(a->front>maxsize){
		a->front%=maxsize;
	}
	return a->q[a->front++];
}
/*void level(node *root){
	if(!root){
	return;
	}
	queue a;
	a.front=0;
	a.rear=0;
	a.size=0;
	while(root||a.size){
		if(root){
		printf("%d ",root->data);
		push(&a,root->left);
		push(&a,root->right);
	}
		root=pop(&a);
	}
}*/
void level(node *root){
	queue a;
	a.front=0;
	a.rear=0;
	a.size=0;
	push(&a,root);
	while(a.size){
		root=pop(&a);
		printf("%d ",root->data);
		if(root->left){
			push(&a,root->left);
		}
		if(root->right){
			push(&a,root->right);
		}
	}
}
int main(){
	
	return 0;
}
