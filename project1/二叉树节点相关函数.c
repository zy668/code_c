#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
	int data;
	struct bintree *left, *right;
}node;
int leaf(node *root){
	if(root==NULL){
		return 0;
	}
	if(!root->left&&!root->right){
		return 1;
	}
	return leaf(root->left)+leaf(root->right);
}
int Node(node *root){
	if(!root){
		return 0;
	}
	return 1+Node(root->left)+Node(root->right);
}
int fullnode(node *root){
	if(root->right&&root->left){
		return 1+fullnode(root->left)+fullnode(root->right);
	}
	else if(root->right){
		return fullnode(root->right);
	}
	else if(root->left){
		return fullnode(root->left);
	}
	return 0;
}
int main(){
	
	return 0;
} 
