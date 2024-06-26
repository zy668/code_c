#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define maxsize 10000
typedef struct edge
{
    int weight;
    int adjvex;
    struct edge *next;
} edge;
typedef struct vertex
{
    char data[20];
    edge *first;
} vertex;
typedef struct graph
{
    vertex adjlist[maxsize];
    int vernum;
    int edgnum;
} graph;
graph *create(int vernum)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->vernum = vernum;
    for (int i = 0; i < vernum; i++)
    {
        g->adjlist[i].first = NULL;
    }
    g->edgnum = 0;
    return g;
}
void addedge(graph *g, int from, int to, int weight)
{
    edge *e = (edge *)malloc(sizeof(edge));
    e->adjvex = to;
    e->weight = weight;
    e->next = g->adjlist[from].first;
    g->adjlist[from].first = e;
    edge *e1 = (edge *)malloc(sizeof(edge));
    e1->adjvex = from;
    e1->weight = weight;
    e1->next = g->adjlist[to].first;
    g->adjlist[to].first = e1;
    g->edgnum++;
}
void addvertex(graph *g, int index)
{
    scanf("%s", g->adjlist[index].data);
}
void dump(graph *g)
{
    printf("GRATH DATA:\n");
    for (int i = 0; i < g->vernum; i++)
    {
        vertex v = g->adjlist[i];
        printf("  %d:[%s]", i, v.data);
        for (edge *e = v.first; e != NULL; e = e->next)
        {
            printf(" ->[%s]%d", g->adjlist[e->adjvex].data, e->weight);
        }
        putchar('\n');
    }
}
void dfsMap(graph *g, int index, bool visited[])
{
    visited[index] = true;
    printf(" %s", g->adjlist[index].data);
    edge *e = g->adjlist[index].first;
    while (e != NULL)
    {
        if (!visited[e->adjvex])
        {
            dfsMap(g, e->adjvex, visited);
        }
        e = e->next;
    }
}
void dfs(graph *g, int index)
{
    printf("DFS(%s): ", g->adjlist[index].data);
    bool visited[maxsize] = {};
    dfsMap(g, index, visited);
    putchar('\n');
}
void prim(graph *g, int path[], int dist[], int startVertex)
{
    bool visited[maxsize] = {};
    int Weight = 0;
    for (int i = 0; i < g->vernum; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[startVertex] = 0;
    path[startVertex] = -1;

    for (int i = 0; i < g->vernum; i++)
    {
        int min = INT_MAX, u = startVertex;
        for (int v = 0; v < g->vernum; v++)
        {
            if (!visited[v] && dist[v] < min)
            {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = true;
        if (path[u] != -1)
        {
            Weight += dist[u];
            printf(" %s-%s(%d)", g->adjlist[path[u]].data, g->adjlist[u].data, dist[u]);
        }
        for (edge *e = g->adjlist[u].first; e != NULL; e = e->next)
        {
            int v = e->adjvex;
            if (!visited[v] && e->weight < dist[v])
            {
                path[v] = u;
                dist[v] = e->weight;
            }
        }
    }
    printf("\n\tWeight of tree: %d\n", Weight);
}
void dijkstra(graph *g, int start, int end, int dist[], int path[])
{
    int i;
    bool visited[maxsize] = {};
    for (i = 0; i < g->vernum; i++)
    {
        dist[i] = INT_MAX;
        path[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < g->vernum - 1; i++)
    {
        int min = INT_MAX, k = -1;
        for (int j = 0; j < g->vernum; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }

        if (k == -1)
            break;
        visited[k] = true;
        if (k == end)
            break;
        edge *e = g->adjlist[k].first;
        while (e != NULL)
        {
            int adjvex = e->adjvex;
            if (!visited[adjvex] && dist[k] + e->weight < dist[adjvex])
            {
                dist[adjvex] = dist[k] + e->weight;
                path[adjvex] = k;
            }
            e = e->next;
        }
    }
}
void freeEdges(edge *e)
{
    while (e != NULL)
    {
        edge *temp = e;
        e = e->next;
        free(temp);
    }
}
void freeGraph(graph *g)
{
    if (g == NULL)
        return;

    for (int i = 0; i < g->vernum; i++)
    {
        freeEdges(g->adjlist[i].first);
    }
    free(g);
}
int main()
{
    char s[15] = "";
    int num;
    graph *g = NULL;
    int dist[maxsize] = {};
    int path[maxsize] = {};

    while (strcmp(s, "BYE") != 0)
    {
        scanf("%s", s);
        if (strcmp(s, "CREATE") == 0)
        {
            scanf("%d", &num);
            g = create(num);
        }
        else if (strcmp(s, "VERTEX") == 0)
        {
            scanf("%d", &num);
            addvertex(g, num);
        }
        else if (strcmp(s, "EDGE") == 0)
        {
            int from, to, weight;
            scanf("%d %d %d", &from, &to, &weight);
            addedge(g, from, to, weight);
        }
        else if (strcmp(s, "DUMP") == 0)
        {
            dump(g);
        }
        else if (strcmp(s, "DFS") == 0)
        {
            scanf("%d", &num);
            dfs(g, num);
        }
        else if (strcmp(s, "SPANNING-TREE") == 0)
        {
            scanf("%d", &num);
            printf("SPANNING-TREE(%s): ", g->adjlist[num].data);
            prim(g, path, dist, num);
        }
        else if (strcmp(s, "SHORTEST-PATH") == 0)
        {
            int from, to;
            scanf("%d %d", &from, &to);
            printf("SHORTEST-PATH(%s=>%s): ", g->adjlist[from].data, g->adjlist[to].data);
            dijkstra(g, to, from, dist, path);
            int p = from;
            while (p != -1)
            {
                printf(" %s", g->adjlist[p].data);
                p = path[p];
            }
            printf("\n\tDistance %d\n", dist[from]);
        }
    }
    freeGraph(g);
    return 0;
}