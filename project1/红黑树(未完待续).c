#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED 0
#define BLACK 1
typedef struct node{
	int data;
	bool color;
	struct node *left,*right,*parent;
}node;
node *create(int val){
	node *a=malloc(sizeof(node));
	a->data=val;
	a->color=RED;
	a->left=a->right=a->parent=NULL;
}
void rotate_left(node *root,node *x){
	node *y=x->right;
	x->right=y->left;
	if(y->left!=NULL){
		y->left->parent=x;
	}
	y->parent=x->parent;
	if(x->parent==NULL){
		root=y;
	}
	else if(x->parent->left==x){
		x->parent->left=y;
	}
	else{
		x->parent->right=y;
	}
	y->left=x;
	x->parent=y;
}
void rotate_right(node *root,node *x){
	node *y=x->left;
	x->left=y->right;
	if(y->right!=NULL){
		y->right->parent=x;
	}
	y->parent=x->parent;
	if(x->parent==NULL){
		root=y;
	}
	else if(x->parent->left=x){
		x->parent->left=y;
	}
	else{
		x->parent->right=y;
	}
	y->right=x;
	x->parent=y;
}
void insert_fixup(node *root,node *z){
	while(z->parent!=NULL&&z->parent->color==RED){
		if(z->parent=z->parent->parent->left){
			node *y=z->parent->parent->right;
			if(y!=NULL&&y->color==RED){
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}
			else{
				if(z==z->parent->right){
					z=z->parent;
					rotate_left(root,z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				rotate_right(root,z->parent->parent);
			}
		}
		else{
			node *y=z->parent->parent->left;
			if(y!=NULL&&y->color==RED){
				y->color=BLACK;
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}
			else{
				if(z==z->parent->left){
					z=z->parent;
					rotate(root,z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				rotate_left(root,z->parent->parent);
			}
		}
	}
	root->color=BLACK;
}
void insert(node *root,int val){
	node *z=create(val);
	node *y=NULL;
	node *x=root;
	while(x!=NULL){
		y=x;
		if(z->data<x->data){
			x=x->left;
		}
		else if(z->data>x->data){
			x=x->right;
		}
		else{
			return;
		}
	}
	z->parent=y;
	if(y==NULL){
		root=z;
	}
	else if(y->data>z->data){
		y->left=z;
	}
	else{
		y->right=z;
	}
	insert_fixup(root,z);
}
int main(){
	
	return 0;
}
