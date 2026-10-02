#include <stdio.h>
#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int n;

void dijkstra(int src) {
    int dist[MAX], visited[MAX], i, j, minDist, u;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        minDist = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; /* remaining vertices are unreachable */

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] != 0 &&
                dist[u] != INF && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nVertex\tShortest Distance from Source %d\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int i, j, src;

    printf("Enter number of vertices (at least 5 recommended): ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix (%dx%d, 0 = no direct edge):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
