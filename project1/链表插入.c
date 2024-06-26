#include <stdio.h>
#include <stdlib.h>
typedef struct linklist{
	int val;
	struct linklist *next;
}node;
int len(node *p){
	int i=0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}
void print(node *a){
	while(a){
		printf("%d ",a->val);
		a=a->next;
	}
}
void insert(node *a,int pos,int ele){
	if(pos<0||pos>=len(a)){
		printf("Error");
	}
	else{
		while(pos--){
			a=a->next;
		}
		node *p=malloc(sizeof(node));
		p->val=ele;
		p->next=a->next;
		a->next=p;
	}
}
int main(){
	node *head=NULL;
	node *last=NULL;
	int n;
	scanf("%d",&n);
	while(n!=-1){
		node *p=malloc(sizeof(node));
		p->val=n;
		p->next=NULL;
		if(head!=NULL){
			last->next=p;
		}
		else{
			head=p;
			last=head;
		}
		if(last->next){
			last=last->next;
		}
		scanf("%d",&n);
	}
	insert(head,2,100);
	print(head);
	return 0;
}
