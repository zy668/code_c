#include <stdio.h>
#include <stdlib.h>
typedef struct linklist{
    int val;
    struct linklist *next;
}node;
void test(node *head){
    node *a=head;
    while(a){
        printf("%d ",a->val);
        a=a->next;
    }
}
int main(){
    int n;
    node *head=NULL;
    node *last=NULL;
    scanf("%d",&n);
    while(n!=-1){
        node *p=malloc(sizeof(node));
        p->val=n;
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
    node *a=head;
test(a);
    return 0;
}