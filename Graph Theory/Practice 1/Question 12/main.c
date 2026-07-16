#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n, m;
    int Edges[100][100];
} Graph;

Graph read_graph()
{
    Graph G;
    scanf("%d %d", &G.n, &G.m);
    for (int i = 0; i < G.m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        if (x == y)
        {
            G.Edges[x][i] = 2;
        }
        else
        {
            G.Edges[x][i] = 1;
            G.Edges[y][i] = 1;
        }
    }
    return G;
}

int calculate_degree(Graph *G, int vertex)
{
    int degree = 0;
    for (int j = 0; j < G->m; j++)
    {
        if (G->Edges[vertex][j] == 1)
        {
            degree++;
        }
        else if (G->Edges[vertex][j] == 2)
        {
            degree += 2;
        }
    }
    return degree;
}

int main()
{
    freopen("graph.txt", "r", stdin);
    Graph G = read_graph();

    // DEBUG
    // for (int i = 0; i < G.n; i++)
    // {
    //     for (int j = 0; j < G.m; j++)
    //     {
    //         printf("%d ", G.Edges[i][j]);
    //     }
    //     printf("\n");
    // }
  
    int vertex_with_max_degree = 0;
    int max_degree = 0;
    for (int i = 0; i < G.n; i++)
    {
        int degree = calculate_degree(&G, i);
        if (degree > max_degree)
        {
            max_degree = degree;
            vertex_with_max_degree = i;
        }
    }
    printf("%d %d\n", ++vertex_with_max_degree, max_degree);
    return 0;
}