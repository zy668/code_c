#include <stdio.h>
#include <stdlib.h>

#define MINDATA -1000000
#define MAXSIZE 100

typedef struct Haffmantree
{
    int data;
    int weight;
    struct Haffmantree *left, *right;
} Htree;

typedef struct heaptree
{
    Htree **ele;
    int size;
    int cap;
} Minheap;

Htree *create(int val, int weigh)
{
    Htree *a = malloc(sizeof(Htree));
    a->data = val;
    a->weight = weigh;
    a->left = a->right = NULL;
    return a;
}

Minheap *createH(int size)
{
    Minheap *a = malloc(sizeof(Minheap));
    a->ele = malloc(sizeof(Htree *) * (size + 1));
    a->ele[0] = create(0, MINDATA);
    a->cap = size;
    a->size = 0;
    return a;
}

int insert(Minheap *a, Htree *b)
{
    if (a->size == a->cap)
    {
        printf("Heap is full.\n");
        return 0;
    }
    int i = ++a->size;
    for (; a->ele[i / 2]->weight > b->weight; i /= 2)
    {
        a->ele[i] = a->ele[i / 2];
    }
    a->ele[i] = b;
    return 1;
}

Htree *del(Minheap *a)
{
    if (a->size == 0)
    {
        printf("Heap is empty.\n");
        return NULL;
    }
    Htree *min = a->ele[1];
    Htree *temp = a->ele[a->size--];
    int parent, child;
    for (parent = 1; parent * 2 <= a->size; parent = child)
    {
        child = parent * 2;
        if (child != a->size && a->ele[child]->weight > a->ele[child + 1]->weight)
        {
            child++;
        }
        if (a->ele[child]->weight >= temp->weight)
        {
            break;
        }
        a->ele[parent] = a->ele[child];
    }
    a->ele[parent] = temp;
    a->ele[a->size + 1] = NULL;
    return min;
}
void printleaf(Htree *root)
{
    if (root == NULL)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        printf("%d", root->data);
    }
    printleaf(root->left);
    printleaf(root->right);
}
int main()
{
    int val, m, i;
    Minheap *b = createH(MAXSIZE);
    for (i = 0; i < 5; i++)
    {
        scanf("%d %d", &val, &m);
        Htree *t = create(val, m);
        insert(b, t);
    }
    for (i = 1; i < 5; i++)
    {
        Htree *T = malloc(sizeof(Htree));
        T->left = del(b);
        T->right = del(b);
        T->data = 0;
        T->weight = T->left->weight + T->right->weight;
        insert(b, T);
    }
    Htree *T = del(b);
    printleaf(T);
    return 0;
}