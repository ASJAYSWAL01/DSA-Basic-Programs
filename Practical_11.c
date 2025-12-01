/*Write a program to implement depth first search (DFS) graph traversal algorithm*/
#include <stdio.h>

#define MAX 50

int visited[MAX];

// DFS Function
void DFS(int graph[MAX][MAX], int n, int node) {
    int i;
    printf("%d ", node);
    visited[node] = 1;

    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, n, i);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(graph, n, start);

    return 0;
}

/*
Example Input :
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
Enter starting vertex: 0

Output:
DFS Traversal: 0 1 2 3
*/