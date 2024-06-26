#include <stdio.h>
#include <stdlib.h>
typedef enum{
	link,thread
}ptag;
typedef struct bintree{
	int data;
	struct bintree *left,*right;
	ptag ltag,rtag;
}node;
node *pre=NULL;
void inthread(node *root){
	if(root){
		inthread(root->left);
		if(!root->left){
			root->ltag=thread;
			root->left=pre;
		}
		if(pre&&!pre->right){
			pre->rtag=thread;
			pre->right=root;
		}
		pre=root;
		inthread(root->right);
	}
}
void intravel(node *root){
	while(root){
		while(root->ltag==link){
			root=root->left;
		}
		printf("%d ",root->data);
		while(root->rtag==thread&&root->right!=NULL){
			root=root->right;
			printf("%d ",root->data);
		}
		root=root->right;
	}
	
}
int main(){
	return 0;
}
