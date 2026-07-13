#pragma once

#include <stdlib.h>

// ==== BEGIN DECLARATIONS ====
#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int list[MAX_VERTICES][MAX_EDGES];
    int adjacentCount[MAX_VERTICES];
    int vertices;
    int edges;
} Graph;
// ==== END DECLARATIONS ====

Graph* initializeGraph(int vertices, int edges)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    
    for (int i = 0; i <= vertices; i++) {
        for (int j = 0; j < MAX_EDGES; j++) {
            graph->list[i][j] = 0;
        }
    }

    for (int i = 0; i <= vertices; i++) {
        graph->adjacentCount[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    if (src > graph->vertices || dest > graph->vertices) {
        return; // Invalid vertex index
    }
    
    graph->list[src][graph->adjacentCount[src]++] = dest;
    if (src != dest)
        graph->list[dest][graph->adjacentCount[dest]++] = src; // for undirected graph
}

void arrangeAdjacent(Graph* graph)
{
    for (int i = 0; i <= graph->vertices; i++) {
        for (int j = 0; j < graph->adjacentCount[i]; j++) {
            for (int k = j + 1; k < graph->adjacentCount[i]; k++) {
                if (graph->list[i][j] > graph->list[i][k]) {
                    int temp = graph->list[i][j];
                    graph->list[i][j] = graph->list[i][k];
                    graph->list[i][k] = temp;
                }
            }
        }
    }
}