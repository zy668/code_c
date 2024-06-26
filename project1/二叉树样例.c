#include <stdio.h>
#include <stdlib.h>

// 二叉搜索树的结构体
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// 创建一个新的节点
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入一个节点
Node* insert(Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return node;
}

// 创建一颗高度为4的二叉搜索树
Node* createBST() {
    Node* root = createNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);
    insert(root, 25);
    insert(root, 35);
    insert(root, 45);
    insert(root, 55);
    insert(root, 65);
    insert(root, 75);
    insert(root, 90);
    return root;
}
int high(Node *root){
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
// 中序遍历二叉搜索树
void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->value);
        inorderTraversal(node->right);
    }
}
int leaf(Node *root){
	if(!root->left&&!root->right){
		return 1;
	}
	return leaf(root->left)+leaf(root->right);
}
int Nodes(Node *root){
	if(!root){
		return 0;
	}
	return 1+Nodes(root->left)+Nodes(root->right);
}
int fullnode(Node *root){
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
void printleaf(Node *root){
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL){
        printf("%d ", root->value);
    }
    printleaf(root->left);
    printleaf(root->right);
}
// 测试代码
int main() {
    Node* root = createBST();
    printleaf(root);
    return 0;
}

