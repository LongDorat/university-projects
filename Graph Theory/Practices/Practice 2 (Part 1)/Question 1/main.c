#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data[100];
    int front, rear;
} Queue;

void make_null_Q(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void enqueue(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}
int front(Queue *Q)
{
    return Q->data[Q->front];
}
void dequeue(Queue *Q)
{
    Q->front++;
}
int empty_Q(Queue *Q)
{
    return Q->front > Q->rear;
}

typedef struct
{
    int Adjacent[100][100];
    int VertexCount;
    int EdgeCount;
} AdjacencyMatrix;

void BFS(AdjacencyMatrix adjacencyMatrix, int root, int *mark)
{
    Queue queue;
    make_null_Q(&queue);

    enqueue(&queue, root);
    while (empty_Q(&queue) != 1)
    {
        int vertex = front(&queue);
        dequeue(&queue);

        if (mark[vertex] == 1)
        {
            continue;
        }

        printf("%d ", vertex);
        mark[vertex] = 1;

        for (int i = 1; i <= adjacencyMatrix.VertexCount; i++)
        {
            if (adjacencyMatrix.Adjacent[vertex][i] == 1 && mark[i] == 0)
            {
                enqueue(&queue, i);
            }
        }
    }

    for (int i = 1; i <= adjacencyMatrix.VertexCount; i++)
    {
        if (mark[i] == 0)
        {
            BFS(adjacencyMatrix, i, mark);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    AdjacencyMatrix adjacencyMatrix;
    fscanf(stdin, "%d %d", &adjacencyMatrix.VertexCount, &adjacencyMatrix.EdgeCount);

    for (int i = 0; i < adjacencyMatrix.EdgeCount; i++)
    {
        int vertex, adjacent;
        fscanf(stdin, "%d %d", &vertex, &adjacent);
        adjacencyMatrix.Adjacent[vertex][adjacent] = 1;
        adjacencyMatrix.Adjacent[adjacent][vertex] = 1;
    }

    int mark[100];
    for (int i = 0; i < adjacencyMatrix.VertexCount; i++)
    {
        mark[i] = 0;
    }

    BFS(adjacencyMatrix, 1, mark);

    return 0;
}