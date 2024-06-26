#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct linklist{
	char c;
	struct linklist* next;
}node;
node* insertsort(node* head) {
    if (!head||!head->next) return head; 
    node *shou=NULL; 
    node *cur =head; 
    while (cur) {
        node *next=cur->next; 
        if (!shou||cur->c<shou->c) { 
            cur->next=shou; 
            shou=cur;
        } else {
            node *p=shou; 
            while (p->next&&cur->c>=p->next->c) {
                p=p->next;
            }
            cur->next=p->next;
            p->next=cur;
        }
        cur=next;
    }
    return shou;
}
void print(node *head){
	if(head==NULL) return;
	while(head->next){
		printf("%c ",head->c);
		head=head->next;
	}
	printf("%c\n",head->c);
}
node *insert(node *a,char b){
    node *new=malloc(sizeof(node));
    new->c=b;
    new->next=NULL;
    if(!a) return new;
    node *p=a;
    while(p->next){
        p=p->next;
    }
    p->next=new;
    return a;
}
int main(){
	node *heada=NULL,*headb=NULL,*headc=NULL;
	int ch;
	while((ch=getchar())!='\n'){
		if(ch==' '){
			continue;
		}
		if(ch=='-'){
			int temp=ch;
			ch=getchar();
			if(ch=='1'){
				break;
			}
			else{
				headc=insert(headc,temp);
				continue
			}
		}
		if(isdigit(ch)){
			headb=insert(headb,ch);
		}
		else if(isalpha(ch)){
			heada=insert(heada,ch);
		}
		else{
			headc=insert(headc,ch);
		}
	}
	heada=insertsort(heada);
	headb=insertsort(headb);
	headc=insertsort(headc);
	if(!heada){
	printf("There is no item in A list.\n");
} else{
	printf("The list A is: ");
	print(heada);
}
if(!headb){
	printf("There is no item in B list.\n");
}
else{
		printf("The list B is: ");
		print(headb);
}
if(!headc){
	printf("There is no item in C list.\n");
}
else{
		printf("The list C is: ");
		print(headc);
}
	return 0;
}
