#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define maxsize 100
typedef struct edge{
	int adjvex;
	int weight;
	struct edge *next;
}edge;
typedef struct vertex{
	int data;
	int in;
	int earliest;
	int latest;
	edge *first;
}vertex;
typedef struct graph{
	vertex adjlist[maxsize];
	int vernum;
	int edgnum;
}graph;
typedef struct stack{
	int ele[maxsize];
	int top;
	int size;
}stack;
void push(stack *s,int val){
	if(s->size==maxsize) printf("FULL");
	else{
		s->ele[++s->top]=val;
		s->top%=maxsize;
		s->size++;
	}
}
int pop(stack *s){
	if(s->size==0){
		printf("Empty");
		return -1;
	}
	int t=s->ele[s->top];
	s->top--;
	s->size--;
	if(s->top<0) s->top+=maxsize;
	return t;
}
void init(graph *g,int num){
	g->vernum=num;
	g->edgnum=0;
	int i;
	for(i=0;i<num;i++){
		g->adjlist[i].data=i;
		g->adjlist[i].in=0;
		g->adjlist[i].earliest=0;
		g->adjlist[i].latest=INT_MAX;
		g->adjlist[i].first=NULL;
	}
}
void addedge(graph *g,int from,int to,int weight){
	edge *e=malloc(sizeof(edge));
	e->adjvex=to;
	e->weight=weight;
	g->adjlist[to].in++;
	e->next=g->adjlist[from].first;
	g->adjlist[from].first=e;
	g->edgnum++;
}
void topsort(graph *g,stack *s){
	int i;
	stack st;
	st.size=0;
	st.top=0;
	for(i=0;i<g->vernum;i++){
		if(g->adjlist[i].in==0){
			push(&st,i);
		}
	}
	while(st.size){
		int v=pop(&st);
		push(s,v);
		edge *e=g->adjlist[v].first;
		while(e){
			int u=e->adjvex;
			g->adjlist[u].in--;
			if(g->adjlist[u].in==0) push(&st,u);
	      	if(g->adjlist[u].earliest<g->adjlist[v].earliest+e->weight){
	        g->adjlist[u].earliest=g->adjlist[v].earliest+e->weight;
	      }
	      e=e->next;
		}
	}
}
void getlatest(graph *g,stack *s){
	while(s->size){
		int u=pop(s);
		edge *e=g->adjlist[u].first;
		while(e){
			int v=e->adjvex;
			if(g->adjlist[u].latest>g->adjlist[v].latest-e->weight){
				g->adjlist[u].latest=g->adjlist[v].latest-e->weight;
			}
			e=e->next;
		}
	}
}
void criticalpath(graph *g){
	int i;
	stack s;
	s.top=s.size=0;
	topsort(g,&s);
	for(i=0;i<g->vernum;i++){
		g->adjlist[i].latest=g->adjlist[g->vernum-1].earliest;
	}
	getlatest(g,&s);
	for(i=0;i<g->vernum;i++){
		edge *e=g->adjlist[i].first;
		while(e){
			int u=e->adjvex;
			if(g->adjlist[i].earliest==g->adjlist[u].earliest-e->weight){
        		printf("%d -> %d weight:%d\n",i,u,e->weight);
			}
			e=e->next;
		}
	}
}
int main(){
  int num=10;
  int i;
  graph g;
  init(&g,num);
  addedge(&g,0,1,6);
  addedge(&g,0,2,4);
  addedge(&g,0,3,5);
  addedge(&g,1,4,1);
  addedge(&g,2,4,1);
  addedge(&g,3,5,2);
  addedge(&g,4,6,9);
  addedge(&g,5,6,7);
  addedge(&g,6,7,8);
	criticalpath(&g);
	return 0;
}
