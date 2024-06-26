#include <stdio.h>
#include <stdlib.h>
#define maxsize 32
typedef struct TreeNode
{
  char val;
  struct TreeNode *left;
  struct TreeNode *right;
} node;
typedef struct queue
{
  node *data[maxsize];
  int front;
  int rear;
  int size;
} queue;
node *pop(queue *a)
{
  if (a->size == 0)
  {
    return NULL;
  }
  a->size--;
  if (a->front > maxsize)
  {
    a->front %= maxsize;
  }
  return a->data[a->front++];
}
int push(queue *a, node *b)
{
  if (a->size == maxsize)
  {
    return 0;
  }
  a->data[a->rear++] = b;
  if (a->rear > maxsize)
  {
    a->rear %= maxsize;
  }
  a->size++;
  return 1;
}
node *create(char val)
{
  node *a = (node *)malloc(sizeof(node));
  a->val = val;
  a->left = NULL;
  a->right = NULL;
  return a;
}
int findIndex(char array[], int start, int end, char value)
{
  for (int i = start; i <= end; i++)
  {
    if (array[i] == value)
      return i;
  }
  return -1;
}

node *createbymidlayer(char mid[], char level[], int midl, int midr, int midn)
{
  if (midl > midr)
    return NULL;
  int i, j;
  int flag = 0;
  for (i = 0; i < midn; i++)
  {
    for (j = midl; j <= midr; j++)
      if (mid[j] == level[i])
      {
        flag = 1;
        break;
      }
    if (flag)
      break;
  }
  node *root = create(level[i]);
  root->left = createbymidlayer(mid, level, midl, j - 1, midn);
  root->right = createbymidlayer(mid, level, j + 1, midr, midn);
  return root;
}
void Pre(node *root, int level)
{
  if (root == NULL)
    return;
  printf("%*s%c\n", level * 4, "", root->val);
  Pre(root->left, level + 1);
  Pre(root->right, level + 1);
}
void Mid(node *root, int level)
{
  if (root == NULL)
    return;

  Mid(root->left, level + 1);
  printf("%*s%c\n", level * 4, "", root->val);
  Mid(root->right, level + 1);
}
void Post(node *root, int level)
{
  if (root == NULL)
    return;
  Post(root->left, level + 1);
  Post(root->right, level + 1);
  printf("%*s%c\n", level * 4, "", root->val);
}
void Level(node *root, int level)
{
  if (root == NULL)
  {
    return;
  }
  queue q;
  q.size = q.front = q.rear = 0;
  push(&q, root);
  while (q.size > 0)
  {
    int n = q.size;
    for (int i = 0; i < n; i++)
    {
      node *p = pop(&q);
      printf("%*s%c\n", level * 4, "", p->val);
      if (p->left != NULL)
      {
        push(&q, p->left);
      }
      if (p->right != NULL)
      {
        push(&q, p->right);
      }
    }
    level++;
  }
}
int height(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int left = height(root->left);
  int right = height(root->right);
  return (left > right ? left : right) + 1;
}
int verify(node *root)
{
  if (root == NULL)
  {
    return 1;
  }
  if (root->left != NULL && root->val > root->left->val)
  {
    return 0;
  }
  if (root->right != NULL && root->val > root->right->val)
  {
    return 0;
  }
  return verify(root->left) && verify(root->right);
}
void swap(node *root)
{
  if (root == NULL)
  {
    return;
  }
  node *temp = root->left;
  root->left = root->right;
  root->right = temp;
  swap(root->left);
  swap(root->right);
}
void after(node *p)
{
  if (p == NULL)
  {
    return;
  }
  after(p->left);
  after(p->right);
  printf("%c", p->val);
}
node *copy(node *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  node *new = (node *)malloc(sizeof(node));
  new->val = root->val;
  new->left = copy(root->left);
  new->right = copy(root->right);
  return new;
}
node *searchParent(node *root, node **parent, char e)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->val == e)
  {
    return root;
  }
  *parent = root;
  node *l = searchParent(root->left, parent, e);
  if (l != NULL)
  {
    return l;
  }
  *parent = root;
  node *r = searchParent(root->right, parent, e);
  return r;
}
void destroyTree(node *root)
{
  if (root == NULL)
  {
    return;
  }
  destroyTree(root->left);
  destroyTree(root->right);
  free(root);
}
void destroy(node *root, char e)
{
  node *parent = NULL;
  node *p = searchParent(root, &parent, e);

  if (p != NULL)
  {
    destroyTree(p);
    if (parent != NULL)
    {
      if (parent->left == p)
      {
        parent->left = NULL;
      }
      else if (parent->right == p)
      {
        parent->right = NULL;
      }
    }
  }
}
int main()
{
  char *a = "abcdefghijk";
  char *b = "dbejgachkfi";
  node *t = createbymidlayer(b, a, 0, 10, 11);
  Pre(t, 0);
  Mid(t, 0);
  Post(t, 0);
  Level(t, 0);
  printf("%d\n", height(t));
  printf("%d\n", verify(t));
  node *t1 = copy(t);
  swap(t1);
  Pre(t1, 0);
  Mid(t1, 0);
  Post(t1, 0);
  Level(t1, 0);
  destroy(t, 'e');
  Pre(t, 0);
  Mid(t, 0);
  Post(t, 0);
  Level(t, 0);
  destroyTree(t);
  destroyTree(t1);
  return 0;
}