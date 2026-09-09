#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX;
    int min_index = -1;
    int v;

    for (v = 0; v < vertices; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMST(int graph[MAX][MAX], int vertices)
{
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];
    int i, count, u, v;

    for (i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < vertices - 1; count++)
    {
        u = minKey(key, mstSet, vertices);

        mstSet[u] = true;

        for (v = 0; v < vertices; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\nEdge\tWeight\n");

    for (i = 1; i < vertices; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int vertices;
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

    primMST(graph, vertices);

    return 0;
}