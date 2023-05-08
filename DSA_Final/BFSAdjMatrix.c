#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int weight[MAX_NODES][MAX_NODES];

int front = -1, rear = -1;

void add_edge(int u, int v, int w) {
    adj[u][v] = 1;
    adj[v][u] = 1;
    weight[u][v] = w;
    weight[v][u] = w;
}

void bfs(int start, int num_nodes) {
    int i, curr_node, curr_weight;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        curr_node = queue[++front];
        printf("%d ", curr_node);

        for (i = 0; i < num_nodes; i++) {
            if (adj[curr_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
                curr_weight = weight[curr_node][i];
            }
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
            weight[i][j] = 0;
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

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal using Adjacency Matrix: ");
    bfs(start, num_nodes);

    return 0;
}
