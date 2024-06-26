#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tablesize 107
typedef struct hashnode{
	char key[10];
	int val;
	int info;
}node;
typedef struct hashtable{
	node *ele;
	int size;
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
	h->size=0;
	h->ele=malloc(sizeof(node)*tablesize);
	int i;
	for(i=0;i<tablesize;i++){
		strcpy(h->ele[i].key,"empty");
		h->ele[i].info=0;
	}
}
int find(hashtable *h,char *s){
	int t=hash(s);
	int cnt=0,k=t;
	if(strcmp(h->ele[k].key,s)==0) return k;
	while(cnt<tablesize*tablesize&&h->ele[k].info){
		if(++cnt%2){
			k=t+(cnt+1)*(cnt+1)/4;
			if(k>=tablesize) k%=tablesize;
		}
		else{
			k=t-cnt*cnt/4;
			if(k<0) k+=tablesize;
		}
	if(strcmp(h->ele[k].key,s)==0) break;
	}
	if(cnt>=tablesize) return -1;
	return k;
}
int insert(hashtable *h,char *s,int num){
	if(h->size==tablesize){
		printf("FULL\n");
		return -1;
	}
	int k=find(h,s);
	if(k==-1) return -1;
	h->ele[k].info=1;
	h->ele[k].val=num;
	strcpy(h->ele[k].key,s);
	h->size++;
	return k;
}
int del(hashtable *h,char *s){
	if(h->size==0){
		printf("Empty\n");
		return -1;
	}
	int t=find(h,s);
	if(t==-1||h->ele[t].info==0){
		printf("Failed");
		return -1;
	}
	h->ele[t].info=0;
	h->size--;
	return t;
}
int main(){
	hashtable ht;
	init(&ht);
	insert(&ht, "apple", 5);
	insert(&ht, "banana", 10);
	insert(&ht,"good",11);
	int index = find(&ht, "apple");
	if (index != -1) {
	  printf("Found index %d with value %d\n", index, ht.ele[index].val);
	}
	return 0;
}
