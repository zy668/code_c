#include <stdio.h>
#include <stdlib.h>
typedef struct linklist{
	int data;
	struct linklist *next;
}node;
node * bubblesort(node *head){
	node *shou=malloc(sizeof(node));
	shou->next=NULL;
	node *cur=head;
	while(head->next)
}
int main(){
	node *head=NULL;
	node *last=NULL;
	int n;
	scanf("%d",&n);
	while(n!=-1){
		node *p=malloc(sizeof(node));
		p->data=n;
		p->next=NULL;
		if(head){
			last->next=p;
			last=last->next;
		}
		else{
			head=p;
			last=head;
		}
		scanf("%d",&n);
	}
	return 0;
} 
