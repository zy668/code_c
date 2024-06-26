#include <stdio.h>
#define maxsize 100
typedef struct arraygraph{
	int vertex[maxsize];
	int edge[maxsize][maxsize];
	int vernum;
	int edgnum;
}graph;
typedef struct arrayqueue{
	int data[maxsize];
	int front;
	int rear;
}queue;
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
	//g->edge[to][from]=weight;  //如果是无向图 
	g->edgnum++;
}
void print_graph(graph *g){
	int i,j;
    printf("顶点数：%d，边数：%d\n", g->vernum, g->edgnum);
    printf("顶点列表：\n");
    for(i=0;i<g->vernum;i++){
        printf("%d ", g->vertex[i]);
    }
    printf("\n邻接矩阵：\n");
    for(i=0; i<g->vernum;i++){
        for(j=0;j<g->vernum;j++){
            printf("%d ",g->edge[i][j]);
        }
        printf("\n");
    }
}
void DFS(graph *g,int v,int *visit){
	visit[v]=1;
	printf("%d ",g->vertex[v]);
	int i;
	for(i=0;i<g->vernum;i++){
		if(g->edge[v][i]>0&&visit[i]==0){
			DFS(g,i,visit);
		}
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
	queue q;
	q.front=0;
	q.rear=0;
	q.data[q.rear]=v;
	q.rear=(q.rear+1)%maxsize;
	while(q.rear!=q.front){
		v=q.data[q.front++];
		q.front%=maxsize;
		printf("%d ",g->vertex[v]);
		int i;
		for(i=0;i<g->vernum;i++){
			if(g->edge[v][i]>0&&!visit[i]){
				q.data[q.rear++]=i;
				visit[i]=1;
				q.rear%=maxsize;
			}
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
int main(){
    graph g;
    init(&g, 5);
    addedge(&g, 0, 1, 1);
    addedge(&g, 0, 2, 2);
    addedge(&g, 1, 3, 3);
    addedge(&g, 2, 3, 4);
    addedge(&g, 2, 4, 5);
	return 0;
}
