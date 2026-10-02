#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, i, curr;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("Visit order: ");
    while (front < rear) {
        curr = queue[front++];
        printf("%d ", curr);

        for (i = 0; i < n; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d), 1 for edge, 0 for no edge:\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
}

int main() {
    int start, i, anyUnreached = 0;

    readGraph();

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(start);

    printf("\nVertices not reached from %d (empty means fully connected from here): ", start);
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("%d ", i);
            anyUnreached = 1;
        }
    }
    if (!anyUnreached)
        printf("none");
    printf("\n");

    return 0;
}
