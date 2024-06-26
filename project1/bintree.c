#include <stdio.h>
typedef struct TreeNode
{
  int val;
  int desc;
  int level;
  struct TreeNode *left;
  struct TreeNode *right;
} node;
int descNum(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int l = descNum(root->left);
  int r = descNum(root->right);
  root->desc = l + r;
  return root->desc + 1;
}
int levelNum(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int l = levelNum(root->left);
  int r = levelNum(root->right);
  root->level = (l > r ? l : r) + 1;
  return root->level + 1;
}
int degNum(node *root)
{
  node *p = root->child;
  int deg = 0;
  while (p != NULL)
  {
    deg++;
  }
  return deg;
}

int maxDeg(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int deg = degNum(root);
  int c = maxDeg(root->child);
  int s = maxDeg(root->sibling);
  return max(deg, c, s);
}
int max(a, b, c)
{
  if (a > b)
  {
    return a > c ? a : c;
  }
  else
  {
    return b > c ? b : c;
  }
}
int main()
{

  return 0;
}