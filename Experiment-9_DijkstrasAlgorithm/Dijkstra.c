#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define INF 99999

int minDistance(int distance[], bool visited[], int n)
{
    int min = INF;
    int minIndex = -1;
    int i;

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && distance[i] < min)
        {
            min = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int source, int n)
{
    int distance[MAX];
    bool visited[MAX];
    int i, count, u, v;

    for (i = 0; i < n; i++)
    {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[source] = 0;

    for (count = 0; count < n - 1; count++)
    {
        u = minDistance(distance, visited, n);

        if (u == -1)
            break;

        visited[u] = true;

        for (v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (distance[i] == INF)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, distance[i]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, source;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, n);

    return 0;
}