#include <stdio.h>
#include <limits.h>
#define maxsize 100
typedef struct arraygraph{
	int vertex[maxsize];
	int edge[maxsize][maxsize];
	int vernum;
	int edgnum;
}graph;
void init(graph *g,int num){
	g->vernum=num;
	g->edgnum=0;
	int i,j;
	for(i=0;i<num;i++){
		g->vertex[i]=i;
		for(j=0;j<num;j++){
			g->edge[i][j]=INT_MAX;
		}
	}
}
void addedge(graph *g,int from,int to,int weight){
	g->edge[from][to]=weight;
	g->edge[to][from]=weight;
	g->edgnum++;
}
void prim(graph *g,int dist[], int parent[]){
  int i,j,k;
  int visit[maxsize]={0};
  int u,min;
  for(i=0;i<g->vernum;i++){
    dist[i]=g->edge[0][i];
    parent[i]=0;
  }
  dist[0]=0;
  visit[0]=1;
  parent[0]=-1;
  for(i=1;i<g->vernum;i++){
    min=INT_MAX;
    for(j=0;j<g->vernum;j++){
      if(!visit[j]&&dist[j]<min){
        min=dist[j];
        u=j;
      }
    }
    visit[u]=1;
    for(k=0;k<g->vernum;k++){
      if(!visit[k]&&g->edge[u][k]<dist[k]){
        dist[k]=g->edge[u][k];
        parent[k]=u;
      }
    }
  }
}
int main(){
    graph g;
    int i;
    init(&g, 10);
  addedge(&g,0,1,6);
  addedge(&g,0,2,4);
  addedge(&g,0,3,5);
  addedge(&g,1,4,1);
  addedge(&g,2,4,1);
  addedge(&g,3,5,2);
  addedge(&g,4,6,9);
  addedge(&g,5,6,7);
  addedge(&g,6,7,8);
    int parent[maxsize];
    int dist[maxsize];
    prim(&g,dist,parent);
    for(i=0;i<g.vernum;i++){
    	printf("%d-%d:%d\n",parent[i],i,dist[i]);
	}
	return 0;
}
