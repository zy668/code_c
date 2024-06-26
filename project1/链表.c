#include<stdio.h>
#include <stdlib.h>
typedef struct linklist{
	int val;
	struct linklist* next;
}node;
int main(){
	int n;
	node *head=NULL;
	do{
		scanf("%d",&n);
		if(n!=-1){
			node *p=(node *)malloc(sizeof(node));
			p->val=n;
			p->next=NULL;
			node *last=head;
			if(last){
				while(last->next){
					last=last->next;
				}
				last->next=p;
			}
			else{
				head=p;
			}
		}
	}while(n!=-1);
	while(head){
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n%p",head);
	return 0;
}
