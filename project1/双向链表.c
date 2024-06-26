#include <stdio.h>
#include <stdlib.h>
typedef struct dlinklist{
	struct dlinklist * bwd;
	int val;
	struct dlinklist * fwd;
}node;
int main(){
	int n;
	node *head=NULL;
	node *last=NULL; 
	scanf("%d",&n);
	while(n!=-1){
		node *p=malloc(sizeof(node));
		p->val=n;
		p->bwd=NULL;
		if(head!=NULL){
			last->bwd=p;
			p->fwd=last;
		}
		else{
			head=p;
			last=head;
		}
		if(last->bwd){
			last=last->bwd;
		}
		scanf("%d",&n);
	}
	node *a=last;
	while(a!=head->fwd){
		printf("%d ",a->val);
		a=a->fwd;
	}
	return 0;
} 
