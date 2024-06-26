#include<stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef struct arrayqueue{
	int data[maxsize];
	int rear;
	int front;
}queue;
typedef struct edgenode{
	int adjvex;
	int weight;
	struct edgenode *next;
}edge;
typedef struct vertexnode{
	int data;
	edge *first;
}vertex;
typedef struct listgraph{
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
//	如果是无向图 
//	edge *e2=malloc(sizeof(edge));
//	e2->adjvex=from;
//	e2->weight=weight;
//	e2->next=g->adjlist[to].first;
//	g->adjlist[to].first=e2;
	g->edgnum++;
}
void print(graph *g){
	printf("graph:\n");
	printf("vertexnum: %d edgenum: %d\n",g->vernum,g->edgnum);
	int i;
	for(i=0;i<g->vernum;i++){
		printf("vertex: %d ",g->adjlist[i].data);
		edge *a=g->adjlist[i].first;
		while(a){
			printf(" %d %d ",a->adjvex,a->weight);
			a=a->next;
		}
		printf("\n");
	}
}
void DFS(graph *g,int v,int *visit){
	visit[v]=1;
	printf("%d ",g->adjlist[v].data);
	edge *e=g->adjlist[v].first;
	while(e){
		if(visit[e->adjvex]==0){
			DFS(g,e->adjvex,visit);
		}
		e=e->next;
	}
}
void DFStraverse(graph *g){
	int visit[maxsize]={0};
	int i;
	for(i=0;i<g->vernum;i++){
		if(visit[i]==0){
			DFS(g,i,visit);
		}
	}
}
void BFS(graph *g,int v,int *visit){
	visit[v]=1;
	printf("%d ",g->adjlist[v].data);
	queue q;
	q.front=0;
	q.rear=0;
	q.data[q.rear]=v;
	q.rear=(q.rear+1)%maxsize;
	while(q.front!=q.rear){
		edge *e=g->adjlist[q.front].first;
		q.front=(q.front+1)%maxsize;
		while(e){
			int u=e->adjvex;
			if(visit[u]==0){
				visit[u]=1;
				printf("%d ",g->adjlist[u].data);
				q.data[q.rear]=u;
				q.rear=(q.rear+1)%maxsize;
			}
			e=e->next;
		}
	}
}
void BFStraverse(graph *g){
	int visit[maxsize]={0};
	int i;
	for(i=0;i<g->vernum;i++){
		if(visit[i]==0){
			BFS(g,i,visit);
		}
	}
}
int main() {
    graph g;
    init(&g, 5);
    addedge(&g, 0, 1, 1);
    addedge(&g, 0, 2, 2);
    addedge(&g, 1, 3, 3);
    addedge(&g, 2, 3, 4);
    addedge(&g, 2, 4, 5);
    print(&g);
    BFStraverse(&g);
    return 0;
}
