#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 505
#define INF INT_MAX

int N, E;
int adj[MAXN][MAXN];
int dist[MAXN][MAXN];
int scc_id[MAXN];
int scc_count;

int min(int a, int b) {
    return a < b ? a : b;
}

void kosaraju(int u, int visited[], int stack[], int *top) {
    visited[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (adj[u][v] && !visited[v]) {
            kosaraju(v, visited, stack, top);
        }
    }
    stack[++(*top)] = u;
}

void reverse_kosaraju(int u, int id, int visited[]) {
    visited[u] = 1;
    scc_id[u] = id;
    for (int v = 1; v <= N; v++) {
        if (adj[v][u] && !visited[v]) {
            reverse_kosaraju(v, id, visited);
        }
    }
}

void find_sccs() {
    int visited[MAXN] = {0};
    int stack[MAXN], top = -1;

    for (int u = 1; u <= N; u++) {
        if (!visited[u]) {
            kosaraju(u, visited, stack, &top);
        }
    }

    for (int u = 1; u <= N; u++) visited[u] = 0;
    scc_count = 0;

    while (top >= 0) {
        int u = stack[top--];
        if (!visited[u]) {
            reverse_kosaraju(u, scc_count++, visited);
        }
    }
}

void floyd_warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = 0;
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }

        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            adj[X][Y] = 1;
            if (dist[X][Y] > H) dist[X][Y] = H;
        }

        find_sccs();

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (scc_id[i] == scc_id[j]) {
                    dist[i][j] = 0;
                }
            }
        }

        floyd_warshall();

        int K;
        scanf("%d", &K);
        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);
            if (dist[O][D] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dist[O][D]);
            }
        }
        printf("\n");
    }
    return 0;
}
