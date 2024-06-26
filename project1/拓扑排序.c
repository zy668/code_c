#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef struct edge{
	int adjvex;
	int weight;
	struct edge *next;
}edge;
typedef struct vertex{
	int in;
	int data;
	edge *first;
}vertex;
typedef struct graph{
	vertex adjlist[maxsize];
	int vernum;
	int edgnum;
}graph;
typedef struct queue{
	int ele[maxsize];
	int front;
	int rear;
}queue;
void push(queue *q,int num){
	q->ele[q->rear]=num;
	q->rear++;
	q->rear%=maxsize;
}
int pop(queue *q){
	int t=q->front;
	q->front++;
	q->front%=maxsize;
	return q->ele[t];
}
void init(graph *g,int num){
	int i;
	for(i=0;i<num;i++){
		g->adjlist[i].in=0;
		g->adjlist[i].data=i;
		g->adjlist[i].first=NULL;
	}
	g->edgnum=0;
	g->vernum=num;
}
void addedge(graph *g,int from,int to,int weight){
	edge *e=malloc(sizeof(edge));
	e->adjvex=to;
	e->weight=weight;
	e->next=g->adjlist[from].first;
	g->adjlist[from].first=e;
	g->adjlist[to].in++;
	g->edgnum++;
}
int topsort(graph *g){
	queue q;
	int c=0,i;
	q.front=q.rear=0;
	for(i=0;i<g->vernum;i++){
		if(g->adjlist[i].in==0){
			push(&q,i);
			c++;
		}
	}
	while(q.rear!=q.front){
		int j=pop(&q);
		printf("%d ",g->adjlist[j].data);
		edge *e=g->adjlist[j].first;
		while(e){
			if(--g->adjlist[e->adjvex].in==0){
				push(&q,e->adjvex);
				c++;
			}
			e=e->next;
		}
	}
	if(c==g->vernum) return 1;
	return 0;
}
int main(){
    graph g;
    init(&g, 5);
    addedge(&g, 0, 1, 1);
    addedge(&g, 0, 2, 2);
    addedge(&g, 1, 3, 3);
    addedge(&g, 2, 3, 4);
    addedge(&g, 2, 4, 5);
    if(topsort(&g)==0) printf("Failed");
	return 0;
} 
