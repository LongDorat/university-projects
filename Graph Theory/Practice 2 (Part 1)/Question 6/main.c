#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vertexes;
    int edges;
    int adjacencyMatrix[100][100];
} Graph;

typedef struct Tracked
{
    int isVisited;
    int parent;
} Tracked;

void DFS(int start, int parent, Graph graph, Tracked *tracked)
{
    if (tracked[start].isVisited == 1)
    {
        return;
    }

    tracked[start].isVisited = 1;
    tracked[start].parent = parent;

    for (int i = 1; i <= graph.vertexes; i++)
    {
        if (graph.adjacencyMatrix[start][i] == 1 && tracked[i].isVisited == 0)
        {
            DFS(i, start, graph, tracked);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertexes, edges;
    scanf("%d %d", &vertexes, &edges);

    Graph graph;
    graph.vertexes = vertexes;
    graph.edges = edges;
    for (int i = 1; i <= vertexes; i++)
    {
        for (int j = 1; j <= vertexes; j++)
        {
            graph.adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph.adjacencyMatrix[u][v] = 1;
        graph.adjacencyMatrix[v][u] = 1;
    }

    Tracked tracked[100];
    for (int i = 1; i <= vertexes; i++)
    {
        tracked[i].isVisited = 0;
        tracked[i].parent = 0;
    }

    for (int i = 1; i <= vertexes; i++)
    {
        if (tracked[i].isVisited == 0)
        {
            DFS(i, 0, graph, tracked);
        }
    }

    for (int i = 1; i <= vertexes; i++)
    {
        printf("Vertex: %d, Parent: %d\n", i, tracked[i].parent);
    }
}