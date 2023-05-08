#include <stdio.h>
#include <stdlib.h>
#define max 9990

//structures
struct node
{
    int val;
    struct node *next;
};

struct queue
{
    struct node *front, *rear;
};

struct graph
{
    int V;
    struct node **adjLists;
    int *visited;
};


//creating node
struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(struct queue *q)
{
    return (q->rear == NULL);
}

void en_queue(struct queue *q, int val)
{
    struct node *newNode = createNode(val);
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int d_queue(struct queue *q)
{
    if (isEmpty(q))
        return -1;
    struct node *temp = q->front;
    int val = temp->val;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

struct graph *createGraph(int V)
{
    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    G->V = V;
    G->adjLists = (struct node **)malloc(V * sizeof(struct node *));
    G->visited = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        G->adjLists[i] = NULL;
        G->visited[i] = 0;
    }
    return G;
}

void addEdge(struct graph *G, int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = G->adjLists[src];
    G->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = G->adjLists[dest];
    G->adjLists[dest] = newNode;
}

void BFS(struct graph *G, int startVertex)
{
    struct queue *q = createQueue();
    G->visited[startVertex] = 1;
    en_queue(q, startVertex);
    while (!isEmpty(q))
    {
        int currentVertex = d_queue(q);
        printf("%d ", currentVertex);
        struct node *temp = G->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->val;
            if (G->visited[adjVertex] == 0)
            {
                G->visited[adjVertex] = 1;
                en_queue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int V, E, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct graph *G = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(G, src, dest);
    }

    /*

        0 --- 1
        |     |
        |     |
        2 --- 3

    */

    printf("Enter starting vertex for BFS: ");
    int start_vertex;
    scanf("%d", &start_vertex);
    printf("BFS Traversal: ");
    BFS(G, start_vertex);

    return 0;
}
