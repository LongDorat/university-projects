#pragma once

// ==== BEGIN DECLARATIONS ====
#define MAX_VERTICES 100
#define MAX_EDGES 200

typedef struct Adjacents
{
    int list[MAX_VERTICES][MAX_EDGES];
    int adjacenCount[MAX_VERTICES];
    int vertices;
    int edges;
} Adjacents;

Adjacents* initializeGraph(int vertices, int edges);
void addEdge(Adjacents* graph, int u, int v);
void arrangeAdjacents(Adjacents* graph);
int hasCycle(Adjacents* graph);
int dfsCycleCheck_directional(Adjacents* graph, int vertex, int* visited, int parent);
// ==== END DECLARATIONS ====

Adjacents* initializeGraph(int vertices, int edges)
{
    Adjacents* newGraph = (Adjacents*)malloc(sizeof(Adjacents));
    newGraph->vertices = vertices;
    newGraph->edges = edges;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        newGraph->list[i][0] = 0;
        newGraph->adjacenCount[i] = 0;
    }
    return newGraph;
}

void addEdge(Adjacents* graph, int u, int v)
{
    graph->list[u][graph->adjacenCount[u]++] = v;

    //? Comment this block if you want directed graph
    // if (u != v) // Avoid adding self-loop twice
    //     graph->list[v][graph->adjacenCount[v]++] = u;
}

// Can swap out for a better sorting algorithm if needed, but this is simple and works for small graphs
void arrangeAdjacents(Adjacents* graph)
{
    for (int i = 1; i <= graph->vertices; i++)
    {
        for (int j = 0; j < graph->adjacenCount[i]; j++)
        {
            for (int k = j + 1; k < graph->adjacenCount[i]; k++)
            {
                if (graph->list[i][j] > graph->list[i][k])
                {
                    int temp = graph->list[i][j];
                    graph->list[i][j] = graph->list[i][k];
                    graph->list[i][k] = temp;
                }
            }
        }
    }
}

int hasCycle(Adjacents* graph)
{
    int visited[MAX_VERTICES] = {0};

    if (graph->vertices == 0)
        return 0; // No vertices, no cycle

    for (int i = 1; i <= graph->vertices; i++)
    {
        if (!visited[i])
        {
            if (dfsCycleCheck_directional(graph, i, visited, -1))
                return 1; // Cycle detected
        }
    }
    return 0; // No cycle detected
}

int dfsCycleCheck_directional(Adjacents* graph, int vertex, int* visited, int parent)
{
    visited[vertex] = 1;

    for (int i = 0; i < graph->adjacenCount[vertex]; i++)
    {
        int adjacentVertex = graph->list[vertex][i];

        if (visited[adjacentVertex] == 1)
            return 1; // Cycle detected

        if (visited[adjacentVertex] == 0)
        {
            if (dfsCycleCheck_directional(graph, adjacentVertex, visited, vertex))
                return 1; // Cycle detected in deeper recursion
        }
    }

    visited[vertex] = 2; // Mark as fully processed
    return 0; // No cycle detected
}