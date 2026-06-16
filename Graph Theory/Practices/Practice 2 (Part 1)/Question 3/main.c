#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int adjacent[100][100];
    int vertexCount;
} VertexToVertexMatrix;

void dfs(VertexToVertexMatrix graph, int vertex, int *tracked)
{
    if (tracked[vertex] == 1)
    {
        return;
    }

    tracked[vertex] = 1;
    printf("%d\n", vertex);

    for (int i = 1; i <= graph.vertexCount; i++)
    {
        if (graph.adjacent[vertex][i] == 1 && tracked[i] == 0)
        {
            dfs(graph, i, tracked);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertexes, edges;
    fscanf(stdin, "%d %d", &vertexes, &edges);

    VertexToVertexMatrix graph;
    graph.vertexCount = vertexes;
    for (int i = 0; i <= vertexes; i++)
    {
        for (int j = 0; j <= vertexes; j++)
        {
            graph.adjacent[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        fscanf(stdin, "%d %d", &a, &b);
        graph.adjacent[a][b] = 1;
        graph.adjacent[b][a] = 1;
    }

    int* tracked = malloc((vertexes + 1) * sizeof(int));
    for (int i = 0; i <= vertexes; i++)
    {
        tracked[i] = 0;
    }
    
    dfs(graph, 1, tracked);
    for (int i = 1; i <= vertexes; i++)
    {
        if (tracked[i] == 0)
        {
            dfs(graph, i, tracked);
        }
    }
    free(tracked);
}