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
        graph.AdjacentCount[v]++;
        graph.Adjacent[v][graph.AdjacentCount[v] - 1] = u;
    }

    for (int i = 1; i < graph.VertexCount; i++)
    {
        MergeSort(graph.Adjacent[i], 0, graph.AdjacentCount[i] - 1);
    }

    return 0;
}