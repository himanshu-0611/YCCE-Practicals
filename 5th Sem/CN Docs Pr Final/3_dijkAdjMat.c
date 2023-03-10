#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("0 is the source node\n");
    printf("Enter the vertex (0-8) till which you have to find the minimum distance from the source: ");
    int v;
    scanf("%d", &v);
    for (int i = 0; i < V; i++)
    {
        if (v == i)
        {
            printf("Distance from source to entered vertex is: %d\n\n", dist[i]);
        }
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0,2,0,6,0,0},
                        {2,0,4,0,3,0},
                        {0,4,0,3,0,9},
                        {6,0,7,0,0,0},
                        {0,3,0,0,0,5},
                        {0,0,9,0,5,0}};

    dijkstra(graph, 0);

    return 0;
}