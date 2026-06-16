#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vertex;
    int parent;
} Node;

typedef struct
{
    Node queue[100];
    int front;
    int rear;
} Queue;

void makeEmpty(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->rear < q->front;
}

Node dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        Node emptyNode = {-1, -1};
        return emptyNode;
    }
    return q->queue[q->front++];
}

void enqueue(Queue *q, Node value)
{
    if (q->rear >= 99)
    {
        return;
    }
    q->queue[++q->rear] = value;
}

typedef struct
{
    int adjacent[100][100];
    int vertices;
} Graph;

void BFS(Graph graph, int start, Node *tracked)
{
    Queue q;
    makeEmpty(&q);

    enqueue(&q, tracked[start]);

    while (!isEmpty(&q))
    {
        Node current = dequeue(&q);
        int u = current.vertex;

        for (int v = 1; v <= graph.vertices; v++)
        {
            if (graph.adjacent[u][v] == 1 && tracked[v].vertex == -1)
            {
                tracked[v].vertex = v;
                tracked[v].parent = u;
                enqueue(&q, tracked[v]);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    Graph graph;
    graph.vertices = vertices;
    for (int i = 0; i <= vertices; i++)
    {
        for (int j = 0; j <= vertices; j++)
        {
            graph.adjacent[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph.adjacent[u][v] = 1;
        graph.adjacent[v][u] = 1;
    }

    Node *tracked = malloc((vertices + 1) * sizeof(Node));
    for (int i = 0; i <= vertices; i++)
    {
        tracked[i].vertex = -1;
        tracked[i].parent = -1;
    }

    for (int i = 1; i <= vertices; i++)
    {
        if (tracked[i].vertex == -1)
        {
            tracked[i].vertex = i;
            tracked[i].parent = 0;
            BFS(graph, i, tracked);
        }
    }

    for (int i = 1; i <= vertices; i++)
    {
        printf("%d %d\n", tracked[i].vertex, tracked[i].parent);
    }
}