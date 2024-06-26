#include <stdio.h>
#include <stdlib.h>
typedef struct linklist{
	int val;
	struct linklist *next;
	
}node;
int len(node*);
void Delete(node *,int);
int main(){
	int n;
	scanf("%d",&n);
	node *head=NULL;
	node *last=NULL;
	while(n!=-1){
		node *p=(node *)malloc(sizeof(node));
		p->val=n;
		p->next=NULL;
		if(head!=NULL){
			last->next=p;
		}
		else{
			head=p;
			last=p;
		}
		if(last->next){
			last=last->next;
		}
		scanf("%d",&n);
	}
	int l=len(head);
	printf("%d\n",l);
	node *a=head;
	Delete(head,2);
	while(a){
		printf("%d ",a->val);
		a=a->next;
	}
	return 0;
}
int len(node *p){
	int i=0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}
void Delete(node *a,int pos){
	if(pos<0||pos>=len(a)){
		printf("Error");
	}
	else{
		node *b=a;
		while(pos--){
			b=a;
			a=a->next;
		}
		b->next=a->next;
		free(a);
	}
}
