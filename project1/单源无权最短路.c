#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
typedef struct queue{
	int data[maxsize];
	int front;
	int rear;
}queue;
void push(queue *q,int val){
	q->data[q->rear++]=val;
	q->rear%=maxsize;
}
int pop(queue *q){
	int temp=q->data[q->front++];
	q->front%=maxsize;
	return temp;
}
typedef struct edge{
	int weight;
	int adjvex;
	struct edge *next;
}edge;
typedef struct vertex{
	int data;
	edge *first;
}vertex;
typedef struct graph{
	vertex adjlist[maxsize];
	int vernum;
	int edgnum;
}graph;
void init(graph *g,int vernum){
	g->vernum=vernum;
	g->edgnum=0;
	int i;
	for(i=0;i<vernum;i++){
		g->adjlist[i].data=i;
		g->adjlist[i].first=NULL;
	}
}
void addedge(graph *g,int from,int to,int weight){
	edge *e=malloc(sizeof(edge));
	e->adjvex=to;
	e->weight=weight;
	e->next=g->adjlist[from].first;
	g->adjlist[from].first=e;
	g->edgnum++;
}
void unweight(graph *g,int *dist,int *path,int s){
	queue *q=malloc(sizeof(queue));
	int v;
	edge *e;
	q->front=0;
	q->rear=0;
	dist[s]=0;
	push(q,s);
	while(q->front!=q->rear){
		v=pop(q);
		e=g->adjlist[v].first;
		while(e){
			if(dist[e->adjvex]==-1){
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				push(q,e->adjvex);
			}
			e=e->next;
		}
	}
}
int main(){
    graph g;
    init(&g, 5);
    addedge(&g, 0, 1, 1);
    addedge(&g, 0, 2, 2);
    addedge(&g, 1, 3, 3);
    addedge(&g, 2, 3, 4);
    addedge(&g, 2, 4, 5);
	int dist[maxsize];
	int path[maxsize];
	memset(dist,-1,maxsize*sizeof(int));
	memset(path,-1,maxsize*sizeof(int));
	unweight(&g,dist,path,0);
	int i;
	for(i=0;i<5;i++){
		printf("%d ",dist[i]);
	}
	return 0;
} 
