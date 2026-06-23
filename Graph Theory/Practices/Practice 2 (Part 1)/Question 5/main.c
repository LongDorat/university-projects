#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    int parent;
} Node;

typedef struct Stack
{
    Node *nodes;
    int top;
    int capacity;
} Stack;

void initStack(Stack *stack, int capacity)
{
    stack->nodes = malloc(capacity * sizeof(Node));
    stack->top = -1;
    stack->capacity = capacity;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int vertex, int parent)
{
    if (stack->top == stack->capacity - 1)
    {
        stack->capacity *= 2;
        stack->nodes = realloc(stack->nodes, stack->capacity * sizeof(Node));
    }
    stack->top++;
    stack->nodes[stack->top].vertex = vertex;
    stack->nodes[stack->top].parent = parent;
}

Node pop(Stack *stack)
{
    return stack->nodes[stack->top--];
}

typedef struct Graph
{
    int vertexes;
    int edges;
    int adjacencyMatrix[100][100];
} Graph;

typedef struct Tracked
{
    int isVisited;
    int parent;
} Tracked;

void DFS(int start, Graph graph, Tracked *tracked)
{
    Stack stack;
    initStack(&stack, graph.vertexes);
    push(&stack, start, 0);

    while (!isEmpty(&stack))
    {
        Node current = pop(&stack);

        if (tracked[current.vertex].isVisited == 0)
        {
            tracked[current.vertex].isVisited = 1;
            tracked[current.vertex].parent = current.parent;

            for (int i = 1; i <= graph.vertexes; i++)
            {
                if (graph.adjacencyMatrix[current.vertex][i] == 1 && tracked[i].isVisited == 0)
                {
                    push(&stack, i, current.vertex);
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int vertexes, edges;
    scanf("%d %d", &vertexes, &edges);

    Graph graph;
    graph.vertexes = vertexes;
    graph.edges = edges;
    for (int i = 1; i <= vertexes; i++)
    {
        for (int j = 1; j <= vertexes; j++)
        {
            graph.adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph.adjacencyMatrix[u][v] = 1;
        graph.adjacencyMatrix[v][u] = 1;
    }

    Tracked tracked[100];
    for (int i = 1; i <= vertexes; i++)
    {
        tracked[i].isVisited = 0;
        tracked[i].parent = 0;
    }

    for (int i = 1; i <= vertexes; i++)
    {
        if (tracked[i].isVisited == 0)
        {
            DFS(i, graph, tracked);
        }
    }

    for (int i = 1; i <= vertexes; i++)
    {
        printf("Vertex: %d, Parent: %d\n", i, tracked[i].parent);
    }
}