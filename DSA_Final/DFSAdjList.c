#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node {
    int data;
    int weight;
    struct node* next;
};

struct node* adj[MAX_NODES];

int visited[MAX_NODES];

void add_edge(int u, int v, int w) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = v;
    new_node->weight = w;
    new_node->next = adj[u];
    adj[u] = new_node;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = u;
    new_node->weight = w;
    new_node->next = adj[v];
    adj[v] = new_node;
}

void dfs(int node) {
    struct node* temp = adj[node];

    visited[node] = 1;
    printf("%d ", node);

    while (temp != NULL) {
        int adj_node = temp->data;
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
        temp = temp->next;
    }
}

int main() {
    int num_nodes, num_edges, i, u, v, w, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_nodes; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (i = 0; i < num_edges; i++) {
        printf("Enter the endpoints and weight of edge %d: ", i+1);
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }

    //          1
    //        /   \
    //      3      2
    //     /      /  \
    //    6      5    4

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal using Adjacency List: ");
    dfs(start);

    return 0;
}
