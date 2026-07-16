#include <stdio.h>
#include <stdlib.h>

#include "MergeSort.h"

typedef struct
{
    int VertexCount;
    int EdgeCount;
    int Adjacent[100][200];
    int AdjacentCount[100];
} Graph;

int DFS(int u, int parent, Graph* graph, int* visited)
{
    visited[u] = 1;
    int parent_count = 0;

    for (int i = 0; i < graph->AdjacentCount[u]; i++)
    {
        int v = graph->Adjacent[u][i];

        if (v == u) return 1;

        if (v == parent)
        {
            parent_count++;
            if (parent_count > 1) return 1;
            continue;
        }

        if (visited[v] == 1) return 1;

        if (DFS(v, u, graph, visited)) return 1;
    }
    return 0;
}

int main()
{
    Graph graph = {0};

    freopen("input.txt", "r", stdin);
    fscanf(stdin, "%d %d", &graph.VertexCount, &graph.EdgeCount);

    for (int i = 0; i < graph.EdgeCount; i++)
    {
        int u, v;
        fscanf(stdin, "%d %d", &u, &v);

        graph.AdjacentCount[u]++;
        graph.Adjacent[u][graph.AdjacentCount[u] - 1] = v;
        if (u != v)
        {
            graph.AdjacentCount[v]++;
            graph.Adjacent[v][graph.AdjacentCount[v] - 1] = u;
        }
    }

    for (int i = 1; i <= graph.VertexCount; i++)
    {
        MergeSort(graph.Adjacent[i], 0, graph.AdjacentCount[i] - 1);
    }

    int visited[100] = {0};
    for (int i = 1; i <= graph.VertexCount; i++)
    {
        if (!visited[i])
            if (DFS(i, 0, &graph, visited))
            {
                printf("The graph has cycle");
                return 0;
            }
    }
    printf("The graph doesn't have cycle");

    return 0;
}