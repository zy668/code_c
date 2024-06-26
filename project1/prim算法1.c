#include <stdio.h>
#include <string.h>
#include <limits.h>
#define maxsize 100
typedef struct graph{
  int vertex[maxsize];
  int edge[maxsize][maxsize];
  int vernum;
  int edgnum;
} graph;

void init(graph *g,int num){
  g->vernum=num;
  g->edgnum=0;
  int i,j;
  for(i=0;i<num;i++){
    g->vertex[i]=i;
    for(j=0;j<num;j++){
      g->edge[i][j]=0;
    }
  }
}
void addedge(graph *g,int from,int to,int weight){
  g->edge[from][to]=weight;
  g->edge[to][from]=weight;
  g->edgnum++;
}
void prim(graph *g,int *parent,int *dist){
  int visit[maxsize]={0};
  int i,j;
  visit[0]=1;
  for(i=1;i<g->vernum;i++){
    int min=INT_MAX;
    int u,v,k;
    for(j=0;j<g->vernum;j++){
      if(visit[j]==0) continue;
      for(k=0;k<g->vernum;k++){
        if(visit[k]==0&&g->edge[j][k]!=0&&g->edge[j][k]<min){
          min=g->edge[j][k];
          u=j;
          v=k;
        }
      }
    }
    visit[v]=1;
    parent[v]=u;
    dist[v]=min;
  }
}
int main(){
  int parent[maxsize];
  int dist[maxsize]={0};
  memset(parent,-1,sizeof(parent));
  graph g;
  init(&g, 5);
  addedge(&g, 0, 1, 1);
  addedge(&g, 0, 2, 2);
  addedge(&g, 1, 3, 3);
  addedge(&g, 2, 3, 4);
  addedge(&g, 2, 4, 5);
  prim(&g,parent,dist);
  int i;
  for(i=0;i<5;i++){
    printf("%d-%d:%d\n",parent[i],i,dist[i]);
  }
  return 0;
}
