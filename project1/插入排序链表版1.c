#include<stdio.h>
#include <stdlib.h>
typedef struct linklist{
	int val;
	struct linklist *next;
}node;
node* insertsort(node* head) {
    if (!head||!head->next) return head; 
    node *shou=NULL; 
    node *cur =head; 
    while (cur) {
        node *next=cur->next; 
        if (!shou||cur->val<shou->val) { 
            cur->next=shou; 
            shou=cur;
        } else {
            node *p=shou; 
            while (p->next&&cur->val>=p->next->val) {
                p=p->next;
            }
            cur->next=p->next;
            p->next=cur;
        }
        cur=next;
    }
    return shou;
}
int main(){
	
	return 0;
} 
