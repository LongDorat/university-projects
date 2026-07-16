#include <stdio.h>
#include <stdlib.h>

typedef struct GraphMatrix {
    int numVertices;
    int numEdges;
    int **adjMatrix;
} GraphMatrix;

int main()
{
    FILE *file = fopen("graph.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    GraphMatrix graph;
    fscanf(file, "%d %d", &graph.numVertices, &graph.numEdges);

    int i, j;
    graph.adjMatrix = (int **)malloc(graph.numVertices * sizeof(int *));
    for (i = 0; i < graph.numVertices; i++) {
        graph.adjMatrix[i] = (int *)malloc(graph.numVertices * sizeof(int));
        for (j = 0; j < graph.numVertices; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }

    for (i = 0; i < graph.numEdges; i++) {
        int src, dest;
        fscanf(file, "%d %d", &src, &dest);
        src--; //? Adjusting for 0-based indexing
        dest--;
        
        graph.adjMatrix[src][dest] = 1;
        graph.adjMatrix[dest][src] = 1;
    }

    for (i = 0; i < graph.numVertices; i++) {
        for (j = 0; j < graph.numVertices; j++) {
            printf("%d ", graph.adjMatrix[i][j]);
        }
        printf("\n");
    }
}