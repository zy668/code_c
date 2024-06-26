#include <stdio.h>
#include <stdlib.h>
#define mindata -1000000
#define maxsize 100
typedef struct Haffmantree{
	int data;
	int weight;
	struct Haffmantree *left,*right;
}htree;
typedef struct heaptree{
	htree **ele;
	int size;
	int cap;
}minheap;
htree* create(int val,int weigh){
	htree *a=malloc(sizeof(htree));
	a->data=val;
	a->weight=weigh;
	a->left=a->right=NULL;
	return a;
}
minheap *createH(int size){
	minheap *a=malloc(sizeof(minheap));
	a->ele=malloc(sizeof(htree*)*(size+1));
	a->ele[0]=malloc(sizeof(htree));
	a->ele[0]->weight=mindata;
	a->ele[0]->left=a->ele[0]->right=NULL;
	a->cap=size;
	a->size=0;
	return a;
}
int insert(minheap *a,htree *b){
	if(a->size==a->cap){
		printf("FULL");
		return 0;
	}
	int i=++a->size;
	for(;a->ele[i/2]->weight>b->weight;i/=2){
		a->ele[i]=a->ele[i/2];
	}
	a->ele[i]=b;
	return 1;
}
htree* del(minheap *a){
	if(a->size==0){
		printf("EMPTY");
		return NULL;
	}
	htree *min,*temp;
	int parent,child;
	min=a->ele[1];
	temp=a->ele[a->size--];
	for(parent=1;parent*2<=a->size;parent=child){
		child=parent*2;
		if(child!=a->size&&a->ele[child]->weight>a->ele[child+1]->weight){
			child++;
		}
		if(a->ele[child]->weight>=temp->weight){
			break;
		}
		else{
		a->ele[parent]=a->ele[child];
	}
	}
	a->ele[parent]=temp;
	return min;
}
void pre(htree *a){
	if(a){
	printf("%d ",a->data);
	pre(a->left);
	pre(a->right);
}
}
int main(){
	int val,m,i;
	minheap *b=createH(maxsize);
	for(i=0;i<5;i++){
		scanf("%d %d",&val,&m);
		htree *a=create(val,m);
		insert(b,a);
	}
	htree *t;
	while(b->size>1){
		t=malloc(sizeof(htree));
		t->left=del(b);
		t->right=del(b);
		t->weight=t->left->weight+t->right->weight;
		t->data=-1;
		insert(b,t);
	}
	t=del(b);
	pre(t);
	return 0;
}
