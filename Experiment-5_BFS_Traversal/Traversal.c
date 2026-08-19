#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int visited[MAX];

void enqueue(int vertex)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = vertex;
}

int dequeue()
{
    int vertex;

    if (front == -1)
        return -1;

    vertex = queue[front];

    if (front >= rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    return vertex;
}

void BFS(int graph[MAX][MAX], int startVertex, int vertices)
{
    int i;
    int currentVertex;

    for (i = 0; i < vertices; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal: ");

    while (front != -1)
    {
        currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main()
{
    int graph[MAX][MAX];
    int vertices;
    int startVertex;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex, vertices);

    return 0;
}