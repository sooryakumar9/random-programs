// Program to implement dijkstra's algorithm to find the distance between source vertext and the shortest path
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

// To find the minimum distance between Source vertex and each vertex
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// To print the path
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

// To print the solution
void printSolution(int dist[], int V, int parent[], int src) {
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < V; i++) {
        printf("\n%d -> %d \t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];
    bool sptSet[MAX];
    int parent[MAX];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
    printSolution(dist, V, parent, src);
}

int main() {
    int V;
    int graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, src, V);
    return 0;
}
