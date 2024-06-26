#include<stdio.h>
#include <stdlib.h>
typedef struct bintree{
    int data;
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
    root->left->right->right->left->data = 7;
    root->right = (node *)malloc(sizeof(node));
    root->right->data = 8;
    root->right->left = (node *)malloc(sizeof(node));
    root->right->left->data = 9;
    root->right->left->left = (node *)malloc(sizeof(node));
    root->right->left->left->data = 10;
    root->right->left->right = (node *)malloc(sizeof(node));
    root->right->left->right->data = 11;
    root->right->left->right->left = (node *)malloc(sizeof(node));
    root->right->left->right->left->data = 12;
    root->right->left->right->right = (node *)malloc(sizeof(node));
    root->right->left->right->right->data = 13;
    return 0;
}