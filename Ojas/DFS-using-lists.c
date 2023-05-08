#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dest;
    struct node* next;
};

struct graph
{
    int V;
    struct node** adjList;
};

struct graph* createGraph(int V)
{
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    G->V = V;
    G->adjList = (struct node**)malloc(V * sizeof(struct node*));
    for (int i = 0; i < V; i++)
    {
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(struct graph* G, int src, int dest)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->next = G->adjList[src];
    G->adjList[src] = newNode;
}

void DFSUtil(struct graph* G, int v, int visited[])
{
    visited[v] = 1;
    printf("%d ", v);
    struct node* temp = G->adjList[v];
    while (temp != NULL)
    {
        int adjV = temp->dest;
        if (visited[adjV] == 0)
        {
            DFSUtil(G, adjV, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct graph* G, int start)
{
    int visited[G->V];
    for (int i = 0; i < G->V; i++)
    {
        visited[i] = 0;
    }
    DFSUtil(G, start, visited);
}

int main()
{
    int V, E, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct graph* G = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(G, src, dest);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &src);
    /*
       0
      / \
     1 - 2
          \
           3

    */
    printf("DFS traversal: ");
    DFS(G, src);
    return 0;}
