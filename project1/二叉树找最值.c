#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
	int data;
	struct bintree *left,*right;
}node;
node * findmin(node *root){
	if(!root){
		return NULL;
	}
	while(root->left){
		root=root->left;
	}
	return root;
}
node * Findmin(node *root){
		if(root&&root->left){
			return Findmin(root->left);
		}
		else{
			return root;
		}
}
//findmaxÍ¬Àí 
int main(){
	
	return 0;
}
