#include <stdio.h>
#include <stdlib.h>

#include "Adjacents.h"

int main()
{
    freopen("input.txt", "r", stdin);
    int vertices, edges;
    fscanf(stdin, "%d %d", &vertices, &edges);

    Adjacents* graph = initializeGraph(vertices, edges);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        fscanf(stdin, "%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    arrangeAdjacents(graph);

    if (hasCycle(graph))
    {
        printf("Graph has a cycle.\n");
    }
    else
    {
        printf("Graph does not have a cycle.\n");
    }

    return 0;
}