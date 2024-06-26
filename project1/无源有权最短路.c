#include <stdio.h>
#include <limits.h>
#define maxsize 100
typedef struct graph{
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
			g->edge[i][j]=0;
		}
	}
}
void addedge(graph *g,int from,int to,int weight){
	g->edge[from][to]=weight;
	//g->edge[to][from]=weight;
	g->edgnum++;
}
int floyd(graph *g,int dist[][g->vernum],int path[][g->vernum]){
	int i,j,k;
	for(i=0;i<g->vernum;i++){
		for(j=0;j<g->vernum;j++){
			if(g->edge[i][j]>0){
				dist[i][j]=g->edge[i][j];
				path[i][j]=i;
			}
			else{
				dist[i][j]=INT_MAX;
				path[i][j]=-1;
			}
		}
		dist[i][i]=0;
	}
	for(k=0;k<g->vernum;k++){
		for(i=0;i<g->vernum;i++){
			for(j=0;j<g->vernum;j++){
				if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][j]>dist[i][k]+dist[k][j]){
//					if(i==j&&dist[i][j]<0) return 0;
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	return 1;
}
int main(){
	
	return 0;
}
