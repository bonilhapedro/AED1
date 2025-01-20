#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int u, v, weight;
} Edge;

int find(int *parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void union_sets(int *parent, int *rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int main() {
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);
        
        if (m == 0 && n == 0) {
            break;
        }

        Edge *edges = (Edge *)malloc(n * sizeof(Edge));
        int total_weight = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].weight = z;
            total_weight += z;
        }

        qsort(edges, n, sizeof(Edge), compare_edges);

        int *parent = (int *)malloc(m * sizeof(int));
        int *rank = (int *)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int mst_weight = 0;
        int edge_count = 0;

        for (int i = 0; i < n && edge_count < m - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int weight = edges[i].weight;

            if (find(parent, u) != find(parent, v)) {
                union_sets(parent, rank, u, v);
                mst_weight += weight;
                edge_count++;
            }
        }

        printf("%d\n", total_weight - mst_weight);

        free(edges);
        free(parent);
        free(rank);
    }

    return 0;
}
