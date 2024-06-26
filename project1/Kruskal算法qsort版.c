#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct edge{
  int u;
  int v;
  int weight;
}edge;

typedef struct graph{
  edge edges[maxsize];
  int vernum;
  int edgenum;
}graph;

int cmp(const void *a, const void *b){
  edge *e1 = (edge*)a;
  edge *e2 = (edge*)b;
  return e1->weight - e2->weight;
}

int find(int parent[], int i){
  if(parent[i] == -1){
    return i;
  }
  return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y){
  int xset = find(parent, x);
  int yset = find(parent, y);
  parent[xset] = yset;
}

void kruskal(graph *g){
  edge result[g->vernum];
  int parent[g->vernum];
  int i, j;
  for(i=0; i<g->vernum; i++){
    parent[i] = -1;
  }

  qsort(g->edges, g->edgenum, sizeof(edge), cmp);

  int e = 0;
  i = 0;
  while(e < g->vernum - 1 && i < g->edgenum){
    edge next_edge = g->edges[i++];
    int x = find(parent, next_edge.u);
    int y = find(parent, next_edge.v);
    if(x != y){
      result[e++] = next_edge;
      unionSet(parent, x, y);
    }
  }

  printf("Kruskal最小生成树：\n");
  int min_weight = 0;
  for(i=0; i<e; i++){
    printf("%d - %d : %d\n", result[i].u, result[i].v, result[i].weight);
    min_weight += result[i].weight;
  }
  printf("最小权值和为：%d\n", min_weight);
}

int main(){
  graph g;
  int num, i;
  printf("请输入顶点数：");
  scanf("%d", &num);
  g.vernum = num;
  g.edgenum = 0;
  for(i=0; i<num; i++){
    printf("请输入第%d个顶点的所有出边信息（格式为：邻接点 权值）, 以-1结束：", i);
    int from, to, weight;
    scanf("%d %d", &to, &weight);
    while(to != -1){
      g.edges[g.edgenum].u = i;
      g.edges[g.edgenum].v = to;
      g.edges[g.edgenum].weight = weight;
      g.edgenum++;
      scanf("%d %d", &to, &weight);
    }
  }

  kruskal(&g);

  return 0;
}
