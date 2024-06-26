#include <stdio.h>
#include <stdlib.h>
#define maxsize 64
typedef struct bintree{
	int data;
	struct bintree *left,*right;
}node;
int high(node *root){
	int i=0,j=0;
	if(!root){
		return 0;
	}
		else{
		i=high(root->left);
		j=high(root->right);
	}
	return 1+(i>j?i:j);
}
int bf(node *root){
//	if(!root){
//	printf("EMPTY\n");
//	return 0;
//}
	return high(root->left)-high(root->right);
}
node *create(int val){
	node * newtree=malloc(sizeof(node));
	newtree->data=val;
	newtree->left=NULL;
	newtree->right=NULL;
	return newtree;
}
node *RR(node *a){
	node *b=a->right;
	a->right=b->left;
	b->left=a;
	return b;
}
node *LL(node *a){
	node *b=a->left;
	a->left=b->right;
	b->right=a;
	return b;
}
node *LR(node *a){
	node *b=a->left;
	node *c=b->right;
	b->right=c->left;
	c->left=b;
	a->left=c->right;
	c->right=a;
	return c;
}
node *RL(node *a){
	node *b=a->right;
	node *c=b->left;
	b->left=c->right;
	c->right=b;
	a->right=c->left;
	c->left=a;
	return c;
}
node *insert(node *root,int val){
	if(!root){
		return create(val);
	}
	if(val>root->data){
		root->right=insert(root->right,val);
	}
	else if(val<root->data){
		root->left=insert(root->left,val);
	}
	if(bf(root)==-2&&root->right->data<val){
		return RR(root);
	}
	else if(bf(root)==2&&root->left->data>val){
		return LL(root);
	}
	else if(bf(root)==-2&&root->right->data>val){
		return RL(root);
	}
	else if(bf(root)==2&&root->left->data<val){
		return LR(root);
	}
	return root;
}
//node *insert(node *root, int val) {
//    if (!root) {
//        return create(val);
//    }
//    if (val > root->data) {
//        root->right = insert(root->right, val);
//    } else if (val < root->data) {
//        root->left = insert(root->left, val);
//    }
//    
//    int balance = bf(root);
//
//    if (balance > 1) {
//        if (val < root->left->data) {
//            return LL(root); // LL case
//        } else if (val > root->left->data) {
//            root->left = RR(root->left); // LR: First perform RR on the left subtree
//            return LL(root); // LR: Then perform LL on the root
//        }
//    }
//
//    if (balance < -1) {
//        if (val > root->right->data) {
//            return RR(root); // RR case
//        } else if (val < root->right->data) {
//            root->right = LL(root->right); // RL: First perform LL on the right subtree
//            return RR(root); // RL: Then perform RR on the root
//        }
//    }
//
//    return root;
//}
void mid(node *a){
	if(a){
	mid(a->left);
	printf("%d ",a->data);
	mid(a->right);
}
}
void pre(node *a){
	if(a){
	printf("%d ",a->data);
	pre(a->left);
	pre(a->right);
}
}
void post(node *a){
	if(a){
	post(a->left);
	post(a->right);
	printf("%d ",a->data);
}
}
typedef struct arrayQueue{
	node * q[maxsize];
	int rear;
	int front;
	int size;
}queue;
int push(queue* a,node *b){
	if(a->size==maxsize){
		printf("FULL");
		return 0;
	}
	a->q[a->rear++]=b;
	if(a->size>maxsize){
		a->size%=maxsize;
	}
	a->size++;
	return 1;
}
node* pop(queue *a){
	if(a->size==0){
		printf("EMPTY");
		return NULL;
	}
	a->size--;
	if(a->front>maxsize){
		a->front%=maxsize;
	}
	return a->q[a->front++];
}
void level(node *root){
	queue a;
	a.front=0;
	a.rear=0;
	a.size=0;
	push(&a,root);
	while(a.size){
		root=pop(&a);
		printf("%d ",root->data);
		if(root->left){
			push(&a,root->left);
		}
		if(root->right){
			push(&a,root->right);
		}
	}
}
node *findmin(node *root){
	if(root==NULL) return NULL;
	while(root->left){
		root=root->left;
	}
	return root;
}
node *del(node *root, int val) {
    if (!root) {
        return NULL;
    }
    if (val < root->data) {
        root->left = del(root->left, val);
    } else if (val > root->data) {
        root->right = del(root->right, val);
    } else {
        if (!root->left && !root->right) {
            free(root);
            root = NULL;
        } else if (!root->left) {
            node *temp = root;
            root = root->right;
            free(temp);
        } else if (!root->right) {
            node *temp = root;
            root = root->left;
            free(temp);
        } else {
            node *temp = findmin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }

    if (!root) {
        return NULL;
    }
//
//    int balance = bf(root);
//
//    if (balance > 1) {
//        if (bf(root->left) < 0) {
//            root->left = RR(root->left);
//        }
//        return LL(root);
//    }
//
//    if (balance < -1) {
//        if (bf(root->right) > 0) {
//            root->right = LL(root->right);
//        }
//        return RR(root);
//    }
	if(bf(root)==-2&&bf(root->right)>0){
		return RL(root);
	}
	else if(bf(root)==2&&bf(root->left)<0){
		return LR(root);
	}
	else if(bf(root)==-2&&bf(root->right)<0){
		return RR(root);
	}
	else if(bf(root)==2&&bf(root->left)>0){
		return LL(root);
	}
    return root;
}
int main(){
    node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 23);
    root = insert(root, 45);
    root = insert(root, 34);
	root = insert(root, 98);
	root = insert(root, 9);
	root = insert(root, 4);
	root = insert(root, 35);
	root = insert(root, 23);
//	mid(root);
//	putchar('\n');
//	pre(root);
//	putchar('\n');
//	post(root);
//	putchar('\n');
	level(root);
	putchar('\n');
	root=del(root,23);
	root=del(root,45);
	level(root);
	return 0;
}
