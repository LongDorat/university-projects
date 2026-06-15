#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data[101];
    int current;
}Stack;

void make_null(Stack *s)
{
    s->current = -1;
}

void push(Stack *s, int x)
{
    s->current++;
    s->data[s->current] = x;
}

int pop(Stack *s)
{
    int x = s->data[s->current];
    s->current--;
    return x;
}

int is_empty(Stack *s)
{
    return s->current == -1;
}

typedef struct
{
    int adjacent[101][101];
    int vertices;
} VertexToVertexMatrix;

void dfs(VertexToVertexMatrix graph, int start, int *tracked)
{
    Stack stack;
    make_null(&stack);
    push(&stack, start);

    while (!is_empty(&stack))
    {
        int u = pop(&stack);
        if (tracked[u] == 1)
        {
            continue;
        }
        tracked[u] = 1;
        printf("%d\n", u);
        for (int v = 1; v <= graph.vertices; v++)
        {
            if (graph.adjacent[u][v] == 1 && tracked[v] == 0)
            {
                push(&stack, v);
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int vertexes, edges;
    scanf("%d %d", &vertexes, &edges);

    VertexToVertexMatrix graph;
    graph.vertices = vertexes;
    for (int i = 0; i <= vertexes; i++)
    {
        for (int j = 0; j <= vertexes; j++)
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

    int tracked[101];
    for (int i = 1; i <= graph.vertices; i++)
    {
        tracked[i] = 0;
    }

    dfs(graph, 1, tracked);

    for (int i = 1; i <= graph.vertices; i++)
    {
        if (tracked[i] == 0)
        {
            dfs(graph, i, tracked);
        }
    }
}