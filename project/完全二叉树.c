#include<stdio.h>
#include <stdlib.h>
typedef struct bintree{
    int data;
    struct bintree *father;
    struct bintree *left;
    struct bintree *right;
}node;
int main(){
    node *root;
    root = (node *)malloc(sizeof(node));
    root->data = 1;
    root->left = (node *)malloc(sizeof(node));
    root->left->data = 2;
    root->left->left = (node *)malloc(sizeof(node));
    root->left->left->data = 3;
    root->left->right = (node *)malloc(sizeof(node));
    root->left->right->data = 4;
    root->left->right->left = (node *)malloc(sizeof(node));
    root->left->right->left->data = 5;
    root->left->right->right = (node *)malloc(sizeof(node));
    root->left->right->right->data = 6;
    root->left->right->right->left = (node *)malloc(sizeof(node));
    return 0;
}