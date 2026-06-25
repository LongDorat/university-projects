#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Edges[500][100];
    int VertexCount;
    int EdgeCount;
} Graph;

int DSU(Graph graph)
{
    int group[100] = {0};

    for (int i = 0; i < graph.EdgeCount; i++)
    {
        // Get the vertices connected by the edge i
        int uv[2];
        int uvIndex = 0;
        for (int j = 1; j <= graph.VertexCount; j++)
        {
            if (graph.Edges[i][j] == 1)
            {
                uv[uvIndex++] = j;
            }
        }

        // If both vertices are different to each other or both of them are zeros then union them
        if ((group[uv[0]] != group[uv[1]]) || (group[uv[0]] == 0 && group[uv[1]] == 0))
        {
            if (group[uv[0]] == 0)
                group[uv[0]] = uv[0];
            group[uv[1]] = group[uv[0]];
        }
        else
        {
            // Catch the cycle immediately
            return 1;
        }
    }

    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertices, edges;
    fscanf(stdin, "%d %d", &vertices, &edges);

    Graph graph;
    graph.VertexCount = vertices;
    graph.EdgeCount = edges;
    for (int i = 0; i < graph.EdgeCount; i++)
    {
        int u, v;
        fscanf(stdin, "%d %d", &u, &v);
        graph.Edges[i][u] = 1;
        graph.Edges[i][v] = 1;
    }

    int isCycle = DSU(graph);
    if (isCycle)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}