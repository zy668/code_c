#include <stdio.h>
#include <stdlib.h>

typedef struct linklist {
    int val;
    struct linklist *next;
} node;

node* merge(node* a, node* b) {
    node *head = malloc(sizeof(node));
    head->next = NULL;
    node *last = head;
    while (a && b) {
        if (a->val <= b->val) {
            last->next = a;
            last = a;
            a = a->next;
        } else {
            last->next = b;
            last = b;
            b = b->next;
        }
    }
    if (a) {
        last->next = a;
    } else if (b) {
        last->next = b;
    }
    return head->next;
}

void print(node *head) {
    if (head == NULL) {
        printf("NULL\n");
    } else {
        while (head->next) {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("%d\n", head->val);
    }
}

int main() {
    int n;
    node *heada = NULL, *lasta = NULL;
    node *headb = NULL, *lastb = NULL;
    scanf("%d", &n);
    while (n != -1) {
        node *p = malloc(sizeof(node));
        p->val = n;
        p->next = NULL;
        if (heada) {
            lasta->next = p;
            lasta = lasta->next;
        } else {
            heada = p;
            lasta = heada;
        }
        scanf("%d", &n);
    }
    scanf("%d", &n);
    while (n != -1) {
        node *p = malloc(sizeof(node));
        p->val = n;
        p->next = NULL;
        if (headb) {
            lastb->next = p;
            lastb = lastb->next;
        } else {
            headb = p;
            lastb = headb;
        }
        scanf("%d", &n);
    }
    node *a = merge(heada, headb);
    print(a);
    return 0;
}
