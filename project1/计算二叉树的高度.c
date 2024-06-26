#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
	int data;
	struct bintree *left,*right;
}node;
int high(node *root){
	int i=0,j=0;
	if(!root){
		return 0;
	}
/*	else{
			i=high(root->left)+1;
			j=high(root->right)+1;
	}
	return i>j?i:j; 
*/
	else{
		i=high(root->left);
		j=high(root->right);
	}
	return 1+(i>j?i:j);
}
int main(){
	node *root;
	return 0;
}
