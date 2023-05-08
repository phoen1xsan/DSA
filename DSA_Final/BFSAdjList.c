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

int queue[MAX_NODES];
int front = -1, rear = -1;

void add_edge(int u, int v, int weight) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = v;
    new_node->weight = weight;
    new_node->next = adj[u];
    adj[u] = new_node;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = u;
    new_node->weight = weight;
    new_node->next = adj[v];
    adj[v] = new_node;
}

void bfs(int start) {
    int i, curr_node, curr_weight;
    struct node* temp;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        curr_node = queue[++front];
        printf("%d ", curr_node);

        temp = adj[curr_node];
        while (temp != NULL) {
            i = temp->data;
            curr_weight = temp->weight;
            if (visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int num_nodes, num_edges, i, u, v, weight, start;

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
        scanf("%d%d%d", &u, &v, &weight);
        add_edge(u, v, weight);
    }

    //          1
    //        /   \
    //      3      2
    //     /      /  \
    //    6      5    4

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal using Adjacency List: ");
    bfs(start);

    return 0;
}
