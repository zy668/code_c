#include <stdio.h>
#include <stdlib.h>
typedef struct bintree
{
	int data;
	struct bintree *left, *right;
} node;
void printleaf(node *root)
{
	if (root == NULL)
	{
		return;
	}
	if (!root->left && !root->right)
	{
		printf("%d", root->data);
	}
	leaf(root->left);
	leaf(root->right);
}
int main()
{

	return 0;
}
