#include <stdio.h>
#include <stdlib.h>
typedef struct bintree
{
	int data;
	struct bintree *left, *right;
} node;
node *create(int val)
{
	node *newtree = malloc(sizeof(node));
	newtree->data = val;
	newtree->left = NULL;
	newtree->right = NULL;
	return newtree;
}
node *insert(node *root, int val)
{
	if (!root)
	{
		return create(val);
	}
	if (val > root->data)
	{
		root->right = insert(root->right, val);
	}
	else if (val < root->data)
	{
		root->left = insert(root->left, val);
	}
	return root;
}
int main()
{
	node *root = NULL;
	insert(root, 36);
	return 0;
}
