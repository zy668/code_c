#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int data;
	int l,r,f;
}tree;
void init(tree *t,int n){
	int i;
	for(i=0;i<n;i++){
		t[i].f=t[i].l=t[i].r=-1;
	}
}
int main(){
	tree a[10];
	return 0;
}
