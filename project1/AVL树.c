#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// 计算节点的高度
int height(Node* node) {
    if (node == NULL) {
        return -1;
    } else {
        return node->height;
    }
}

// 计算节点的平衡因子
int balance_factor(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return height(node->left) - height(node->right);
    }
}

// 左旋转
Node* rotate_left(Node* node) {
    Node* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;

    node->height = 1 + fmax(height(node->left), height(node->right));
    new_root->height = 1 + fmax(height(new_root->left), height(new_root->right));

    return new_root;
}

// 右旋转
Node* rotate_right(Node* node) {
    Node* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;

    node->height = 1 + fmax(height(node->left), height(node->right));
    new_root->height = 1 + fmax(height(new_root->left), height(new_root->right));

    return new_root;
}

// 右左旋转
Node* rotate_right_left(Node* node) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
}

// 左右旋转
Node* rotate_left_right(Node* node) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

// 插入节点
Node* insert(Node* node, int value) {
    if (node == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 0;
        return new_node;
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    node->height = 1 + fmax(height(node->left), height(node->right));

    int bf = balance_factor(node);

    if (bf > 1 && value < node->left->value) {
        return rotate_right(node);
    }

    if (bf > 1 && value > node->left->value) {
        return rotate_left_right(node);
    }

    if (bf < -1 && value > node->right->value) {
        return rotate_left(node);
    }

    if (bf < -1 && value < node->right->value) {
        return rotate_right_left(node);
    }

    return node;
}

// 中序遍历
void inorder(Node* node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    printf("%d ", node->value);
    inorder(node->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	printf("Inorder traversal of the AVL tree: ");
	inorder(root);

return 0;
}
 

