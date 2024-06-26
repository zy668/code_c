#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tablesize 100
typedef struct hashnode{
	char key[10];
	int val;
	struct hashnode *next;
}node;
typedef struct hashtable{
	node *ele[tablesize];
}hashtable;
int hash(char *s){
	int i=0;
	int sum=0;
	while(s[i]!='\0'){
		sum=sum*2+s[i]-'a';
		i++;
	}
	return sum%tablesize;
}
void init(hashtable *h){
	int i;
	for(i=0;i<tablesize;i++){
		h->ele[i]=NULL;
	}
}
node *create(char *s,int num){
	node *m=malloc(sizeof(node));
	strcpy(m->key,s);
	m->val=num;
	m->next=NULL;
	return m;
}
int find(hashtable *h,char *s){
	int t=hash(s);
	node *m=h->ele[t];
	while(m){
		if(strcmp(m->key,s)==0){
			break;
		}
		m=m->next;
	}
	if(m==NULL) return -1;
	return t;
}
int insert(hashtable *h,char *s,int num){
	int t=hash(s);
	node *m=h->ele[t];
	if(h->ele[t]==NULL){
		h->ele[t]=create(s,num);
	}
	else{
		while(m){
			if(strcmp(m->key,s)==0){
				m->val=num;
				break;
			}
			m=m->next;
		}
		if(m==NULL){
			m=create(s,num);
		}
	}
//	if(m==NULL){
//		h->ele[t]=create(s,num);
//		return t;
//	}
//	while(m->next){
//		if(strcmp(m->key,s)==0){
//			break;
//		}
//		m=m->next;
//	}
//	if(strcmp(m->key,s)==0||m->next){
//		m->val=num;
//	}
//	else{
//		m->next=create(s,num);
//	}
	return t;
}
int del(hashtable *h,char *s){
	int t=hash(s);
	node shou;
	shou.next=h->ele[t];
	node *m=h->ele[t];
	node *pre=&shou;
	while(m){
		if(strcmp(m->key,s)==0){
			break;
		}
		pre=m;
		m=m->next;
	}
	if(m==NULL){
		printf("Failed");
		return -1;
	}
	pre->next=m->next;
	free(m);
	return t;
}
int main(){
	hashtable ht;
	init(&ht);
	insert(&ht, "apple", 5);
	insert(&ht, "banana", 10);
	int index = find(&ht, "apple");
	if (index != -1) {
	  printf("Found apple at index %d with value %d\n", index, ht.ele[index]->val);
	}
	return 0;
}
