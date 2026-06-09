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
    int Edge[100][100];
    int VertexCount;
    int EdgeCount;
} VertexList;

void BFS(VertexList vertexList, int root, int *mark)
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

        for (int i = 1; i <= vertexList.VertexCount; i++)
        {
            if (vertexList.Edge[vertex][i] == 1 && mark[i] == 0)
            {
                enqueue(&queue, i);
            }
        }
    }

    for (int i = 1; i <= vertexList.VertexCount; i++)
    {
        if (mark[i] == 0)
        {
            BFS(vertexList, i, mark);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    VertexList vertexList;
    fscanf(stdin, "%d %d", &vertexList.VertexCount, &vertexList.EdgeCount);

    for (int i = 0; i < vertexList.EdgeCount; i++)
    {
        int vertex, adjacent;
        fscanf(stdin, "%d %d", &vertex, &adjacent);
        vertexList.Edge[vertex][adjacent] = 1;
        vertexList.Edge[adjacent][vertex] = 1;
    }

    int mark[100];
    for (int i = 0; i < vertexList.VertexCount; i++)
    {
        mark[i] = 0;
    }

    BFS(vertexList, 1, mark);

    return 0;
}