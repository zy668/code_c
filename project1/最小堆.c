#include <stdio.h>
#include <stdlib.h>
#define mindata -1000000
typedef struct heaptree{
	int *ele;
	int size;
	int cap;
}minheap;
minheap *create(int size){
	minheap *a=malloc(sizeof(minheap));
	a->ele=malloc(sizeof(int)*(size+1));
	a->ele[0]=mindata;
	a->cap=size;
	a->size=0;
	return a;
}
int insert(minheap *a,int val){
	if(a->size==a->cap){
		printf("FULL");
		return 0;
	}
	int i=++a->size;
	for(;a->ele[i/2]>val;i/=2){
		a->ele[i]=a->ele[i/2];
	}
	a->ele[i]=val;
	return 1;
}
int del(minheap *a){
	if(a->size==0){
		printf("EMPTY");
		return -1;
	}
	int parent,child,temp,min;
	min=a->ele[1];
	temp=a->ele[a->size--];
	for(parent=1;parent*2<=a->size;parent=child){
		child=parent*2;
		if(child!=a->size&&a->ele[child]>a->ele[child+1]){
			child++;
		}
		if(a->ele[child]>=temp){
			break;
		}
		else{
		a->ele[parent]=a->ele[child];
	}
	}
	a->ele[parent]=temp;
	return min;
}
int main(){
    int n,m,i,j;
    scanf("%d",&n);
    minheap *H=create(n);
    for(i=0;i<n;i++){
        scanf("%d",&j);
        insert(H,j);
    }
    for(i=0;i<=n;i++){
    	printf("%d ",H->ele[i]);
	}
	return 0;
}
