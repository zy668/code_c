#include <stdio.h>
#include <stdlib.h>

// 链表结构体
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建链表节点
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 插入节点
void insert(ListNode* head, ListNode* node) {
    ListNode* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
}

// 遍历链表
void printList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

// 交换节点
void swap(ListNode* p, ListNode* q) {
    int temp = p->val;
    p->val = q->val;
    q->val = temp;
}

// 冒泡排序
void bubbleSort(ListNode* head) {
    ListNode* p = head->next;
    while (p != NULL) {
        ListNode* q = head->next;
        while (q->next != NULL) {
            if (q->val > q->next->val) {
                swap(q, q->next);
            }
            q = q->next;
        }
        p = p->next;
    }
}

// 选择排序
void selectionSort(ListNode* head) {
    ListNode* p = head->next;
    while (p != NULL) {
        ListNode* q = p->next;
        ListNode* min = p;
        while (q != NULL) {
            if (q->val < min->val) {
                min = q;
            }
            q = q->next;
        }
        swap(p, min);
        p = p->next;
    }
}

// 插入排序
void insertionSort(ListNode* head) {
    ListNode* p = head->next->next;
    while (p != NULL) {
        int temp = p->val;
        ListNode* q = head;
        while (q->next != p && q->next->val < temp) {
            q = q->next;
        }
        ListNode* node = createNode(temp);
        node->next = q->next;
        q->next = node;
        ListNode* next = p->next;
        free(p);
        p = next;
    }
}

// 快速排序
ListNode* partition(ListNode* start, ListNode* end) {
    int pivot = start->val;
    ListNode* p = start;
    ListNode* q = start->next;
    while (q != end) {
        if (q->val < pivot) {
            p = p->next;
            swap(p, q);
        }
        q = q->next;
    }
    swap(start, p);
    return p;
}

void quickSort(ListNode* start, ListNode* end) {
    if (start == end || start->next == end) {
        return;
    }
    ListNode* pivot = partition(start, end);
    quickSort(start, pivot);
    quickSort(pivot->next, end);
}

int main() {
    ListNode* head = createNode(0);
    int n, x,i;
    printf("请输入链表的长度: ");
    scanf("%d", &n);
    printf("请输入链表的元素: ");
    for(i = 0; i < n; i++) {
    scanf("%d", &x);
    insert(head, createNode(x));
}

printf("排序前的链表: ");
printList(head);

// 冒泡排序
bubbleSort(head);
printf("冒泡排序后的链表: ");
printList(head);

// 选择排序
selectionSort(head);
printf("选择排序后的链表: ");
printList(head);

// 插入排序
insertionSort(head);
printf("插入排序后的链表: ");
printList(head);

// 快速排序
quickSort(head->next, NULL);
printf("快速排序后的链表: ");
printList(head);

return 0;
}
