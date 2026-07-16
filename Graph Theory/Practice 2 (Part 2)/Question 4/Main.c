#include <stdio.h>
#include <stdlib.h>

#include "Adjacents.h"

void splitTeam(Graph* graph)
{
    int color[MAX_VERTICES];
    for (int i = 0; i <= graph->vertices; i++)
        color[i] = -1;

    for (int i = 1; i <= graph->vertices; i++)
    {
        if (color[i] != -1)
        {
            continue;
        }

        color[i] = 0;
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;
        queue[rear++] = i;

        while (front < rear)
        {
            int current = queue[front++];

            for (int j = 0; j < graph->adjacentCount[current]; j++)
            {
                int neighbor = graph->list[current][j];

                if (color[neighbor] == -1)
                {
                    color[neighbor] = 1 - color[current];
                    queue[rear++] = neighbor;
                }
                else if (color[neighbor] == color[current])
                {
                    printf("Graph is not bipartite.\n");
                    return;
                }
            }
        }
    }
    printf("Graph is bipartite.\n");

    int teamA[MAX_VERTICES], teamB[MAX_VERTICES];
    int countA = 0, countB = 0;
    for (int i = 1; i <= graph->vertices; i++)
    {
        if (color[i] == 0)
            teamA[countA++] = i;
        else if (color[i] == 1)
            teamB[countB++] = i;
    }
    
    printf("Team A: ");
    for (int i = 0; i < countA; i++)
        printf("%d ", teamA[i]);
    printf("\n");

    printf("Team B: ");
    for (int i = 0; i < countB; i++)
        printf("%d ", teamB[i]);
    printf("\n");
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertices, edges;
    fscanf(stdin, "%d %d", &vertices, &edges);
    
    Graph* graph = initializeGraph(vertices, edges);
    
    for (int i = 0; i < edges; i++) {
        int src, dest;
        fscanf(stdin, "%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    arrangeAdjacent(graph);
    
    splitTeam(graph);
    
    return 0;
}