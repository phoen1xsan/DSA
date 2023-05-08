#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj[MAX_NODES][MAX_NODES];
int weights[MAX_NODES][MAX_NODES];

int visited[MAX_NODES];

void add_edge(int u, int v, int w) {
    adj[u][v] = 1;
    adj[v][u] = 1;
    weights[u][v] = w;
    weights[v][u] = w;
}

void dfs(int node, int num_nodes) {
    int i;

    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < num_nodes; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, num_nodes);
        }
    }
}

int main() {
    int num_nodes, num_edges, i, u, v, w, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_nodes; i++) {
        visited[i] = 0;
        for (int j = 0; j < num_nodes; j++) {
            adj[i][j] = 0;
            weights[i][j] = 0;
        }
    }

    for (i = 0; i < num_edges; i++) {
        printf("Enter the endpoints and weight of edge %d: ", i+1);
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }

    //          0
    //        /   \
    //      1      2
    //     / \   /
    //    3   4
    //     \  /
    //       5

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal using Adjacency Matrix: ");
    dfs(start, num_nodes);

    return 0;
}
