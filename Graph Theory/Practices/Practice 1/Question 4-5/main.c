#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

// typedef struct
// {
//     int x, y;
// } Edge;

typedef struct
{
    int n, m;
    int Edges[100][500];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int e, int x, int y)
{
    if (x < 1 || y < 1 || x > G->n || y > G->n)
    {
        return;
    }

    if (x == y)
    {
        G->Edges[x][e] = 2;
    }
    else
    {
        G->Edges[x][e] = 1;
        G->Edges[y][e] = 1;
    }
    G->m++;
}

int deg(Graph *G, int v)
{
    int degree = 0;
    for (int i = 0; i < G->m; i++)
    {
        if (G->Edges[v][i] == 1)
        {
            degree++;
        }
        else if (G->Edges[v][i] == 2)
        {
            degree += 2;
        }
    }
    return degree;
}

int main()
{
    Graph G;
    init_graph(&G, 5);
    add_edge(&G, 0, 1, 2);
    add_edge(&G, 1, 1, 3);
    add_edge(&G, 2, 2, 3);
    add_edge(&G, 3, 3, 4);
    add_edge(&G, 4, 4, 4);

    printf("Graph has %d vertices and %d edges.\n", G.n, G.m);
    for (int i = 0; i < G.m; i++)
    {
        printf("Edge %d: ", i);
        for (int j = 1; j <= G.n; j++)
        {
            if (G.Edges[j][i] == 2)
            {
                printf("%d (loop) ", j);
            }
            else if (G.Edges[j][i] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    for (int v = 1; v <= G.n; v++)
    {
        printf("Degree of vertex %d: %d\n", v, deg(&G, v));
    }

    return 0;
}