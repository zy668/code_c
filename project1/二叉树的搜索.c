#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
	int data;
	struct bintree *left, *right;
}node;
node *find(node *root,int val){
	if(root){
		if(val>root->data){
			return find(root->right,val);
		}
		else if(val<root->data){
			return find(root->left,val);
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
