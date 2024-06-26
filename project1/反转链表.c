#include<stdio.h>
#include <stdlib.h>
typedef struct linklist{
	int val;
	struct linklist *next;
}node;
node* reverse(node* a){
  if (a == NULL || a->next == NULL) {
  return a;
  }
  node* b = a;
  a=a->next;
  node* c = a->next;
  b->next = NULL; 
  while (c != NULL) {
    a->next = b; 
    b = a;       
    a = c;        
    c = a->next; 
  }
  a->next = b; 
  return a;
}
int main(){
	int n;
	node *head=NULL;
	node *last=NULL;
  while (scanf("%d", &n) == 1 && n != -1) {
    node *p = malloc(sizeof(node));
    p->val = n;
    p->next = NULL;
    if (head) {
      last->next = p;
      last = p;
    } else {
      head = p;
      last = head;
    }
  }
	node *a=reverse(head);
	while(a){
		printf("%d ",a->val);
		a=a->next;
	}
	return 0;
}
