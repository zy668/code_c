#include <stdio.h>
#include <stdlib.h>
typedef struct bintree
{
	int data;
	struct bintree *left, *right;
} node;
void pre(node *a)
{
	if (a)
	{
		printf("%d ", a->data);
		pre(a->left);
		pre(a->right);
	}
}
// void mid(node *a){
//	if(a){
//	mid(a->left);
//	printf("%d ",a->data);
//	mid(a->right);
// }
// }
void rmid(node *root)
{
	if (root)
	{
		rmid(root->right);
		printf("%d", root->data);
		rmid(root->left);
	}
}
void post(node *a)
{
	if (a)
	{
		post(a->left);
		post(a->right);
		printf("%d ", a->data);
	}
}
void mid(node *a)
{
	if (!a)
		return;
	mid(a->left);
	printf("%d ", a->data);
	mid(a->right);
}
node *newNode(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
node *insertLevelOrder(int arr[], int i, int n)
{
	// Base case for recursion
	if (i < n)
	{
		node *root = newNode(arr[i]);

		// Insert left child
		root->left = insertLevelOrder(arr, 2 * i + 1, n);

		// Insert right child
		root->right = insertLevelOrder(arr, 2 * i + 2, n);
		return root;
	}
	return NULL;
}
void prinleaf(node *root)
{
	if (root == NULL)
	{
		return;
	}
	if (!root->left && !root->right)
	{
		printf("%d", root->data);
	}
}
int main()
{
	// node *root = NULL;
	int a[] = {
			5,
			3,
			7,
			2,
	};
	node *root = insertLevelOrder(a, 0, 9);
	pre(root);
	putchar('\n');
	mid(root);
	putchar('\n');
	post(root);
	return 0;
}
