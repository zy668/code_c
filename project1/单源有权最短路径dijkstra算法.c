#include <stdio.h>
#include <limits.h>
#define maxsize 100
typedef struct arraygraph
{
	int vertex[maxsize];
	int edge[maxsize][maxsize];
	int vernum;
	int edgnum;
} graph;
void init(graph *g, int num)
{
	g->vernum = num;
	g->edgnum = 0;
	int i, j;
	for (i = 0; i < num; i++)
	{
		g->vertex[i] = i;
		for (j = 0; j < num; j++)
		{
			g->edge[i][j] = 0;
		}
	}
}
void addedge(graph *g, int from, int to, int weight)
{
	g->edge[from][to] = weight;
	g->edge[to][from] = weight;
	g->edgnum++;
}
void dijkstra(graph *g, int start, int dist[], int path[])
{
	int i, j, k;
	int visit[maxsize] = {0};
	for (i = 0; i < g->vernum; i++)
	{
		if (g->edge[start][i] > 0)
		{
			dist[i] = g->edge[start][i];
			path[i] = start;
		}
		else
		{
			dist[i] = INT_MAX;
			path[i] = -1;
		}
	}
	dist[start] = 0;
	visit[start] = 1;
	for (i = 0; i < g->vernum - 1; i++)
	{
		int min = INT_MAX;
		for (j = 0; j < g->vernum; j++)
		{
			if (!visit[j] && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		visit[k] = 1;
		for (j = 0; j < g->vernum; j++)
		{
			if (!visit[j] && g->edge[k][j] && dist[k] + g->edge[k][j] < dist[j])
			{
				dist[j] = dist[k] + g->edge[k][j];
				path[j] = k;
			}
		}
	}
}
int main()
{
	graph g;
	int i;
	init(&g, 5);
	addedge(&g, 0, 1, 1);
	addedge(&g, 0, 2, 2);
	addedge(&g, 1, 3, 3);
	addedge(&g, 2, 3, 4);
	addedge(&g, 2, 4, 5);
	int path[maxsize];
	int dist[maxsize];
	dijkstra(&g, 0, dist, path);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", dist[i]);
	}
	putchar('\n');
	for (i = 0; i < 5; i++)
	{
		printf("%d ", path[i]);
	}
	return 0;
}
