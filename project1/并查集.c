#include <stdio.h>
#define maxsize 10
typedef struct set{
	int data;
	int parent;
}set;
int find(set *s,int x){
	int i;
	for(i=0;i<maxsize&&s[i].data!=x;i++);
	if(i==maxsize) return -1;
	for(;s[i].parent>=0;i=s[i].parent);
	return i;
}
void unionset(set *s,int x1,int x2){
	int a=find(s,x1);
	int b=find(s,x2);
	if(a!=b){
		s[b].parent=a;
	}
}
int main(){
	set s[maxsize];
	
	return 0;
}
