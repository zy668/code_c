#include <stdio.h>
#include <stdlib.h>
#define maxdata 1000000
typedef struct heaptree{
	int *ele;
	int size;
	int cap;
}maxheap;
maxheap* create(int size){
	maxheap *H=malloc(sizeof(maxheap));
	H->ele=malloc(sizeof(int)*(size+1));
	H->size=0;
	H->cap=size;
	H->ele[0]=maxdata;
	return H;
}
int insert(maxheap *H,int val){
	if(H->cap==H->size){
		printf("FULL");
		return 0;
	}
	else{
		int i=H->size+1;
		for(;val>H->ele[i/2];i/=2){
			H->ele[i]=H->ele[i/2];
		}
		H->ele[i]=val;
	}
	return 1;
}
int del(maxheap *H){
	int parent,child,max,temp; 
	if(H->size==0){
		printf("EMPTY");
		return -1;
	}
	max=H->ele[1];
	temp=H->ele[H->size--];
	for(parent=1;parent*2<=H->size;parent=child){
		child=parent*2;
		if(child!=H->size&&H->ele[child]<H->ele[child+1]){
			child++;
		}
		if(temp>=H->ele[child]){
			break;
		}
		else{
		H->ele[parent]=H->ele[child];
	}
	}
	H->ele[parent]=temp;
	return max;
}
int main(){
	
	return 0;
}
