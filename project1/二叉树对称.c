#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
	int data;
	struct bintree *left,*right;
}node;
node *create(int val){
	node *p=malloc(sizeof(node));
	p->data=val;
	p->left=p->right=NULL;
	return p;
}
node *insert(node *root,int val){
	if(!root) return create(val);
	if(root->data>val){
		root->left=insert(root->left,val);
	}
	else if(root->data<val){
		root->right=insert(root->right,val);
	}
	return root;
}
void mirror(node *root){
	if(!root) return;
	node *p=root->left;
	root->left=root->right;
	root->right=p;
	mirror(root->left);
	mirror(root->right);
}
void mid(node *root){
	if(!root) return;
	mid(root->left);
	printf("%d ",root->data);
	mid(root->right);
}
int main(){
	node *root=NULL;
	root=insert(root,6);
	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,5);
	root=insert(root,4);
	mid(root);
	putchar('\n');
	mirror(root);
	mid(root);
	return 0;
}
