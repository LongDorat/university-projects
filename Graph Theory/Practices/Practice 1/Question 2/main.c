#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct
{
    int x, y;
} Edge;

typedef struct
{
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph* G, int x, int y) {
    if (G->m < MAX_EDGES) {
        G->edges[G->m].x = x;
        G->edges[G->m].y = y;
        G->m++;
    }
}

int main()
{
    Graph G;
    init_graph(&G, 5);
    add_edge(&G, 0, 1);
    add_edge(&G, 0, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 2, 3);
    add_edge(&G, 3, 4);

    printf("Graph has %d vertices and %d edges.\n", G.n, G.m);
    for (int i = 0; i < G.m; i++) {
        printf("Edge from %d to %d\n", G.edges[i].x, G.edges[i].y);
    }

    return 0;
}