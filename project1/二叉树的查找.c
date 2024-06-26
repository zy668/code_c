#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
	int data;
	struct bintree *left, *right;
}node;
node *Find(node *root,int val){
	if(root){
		if(val>root->data){
			return Find(root->right,val);
		}
		else if(val<root->data){
			return Find(root->left,val);
		}
		else{
			return root;
		}
	}
	return NULL;
}
node *find(node *root,int val){
	while(root){
		if(val>root->data){
			root=root->right;
		}
		else if(val<root->data){
			root=root->left;
		}
		else{
			return root;
		}
	}
	return NULL;
}
int main(){
	return 0;
}
