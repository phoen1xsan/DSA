#include <stdio.h>
#include<stdlib.h>
#define MAX 999

struct Node{
    int vertex;
    int weight;
    struct Node *next;
};

void readGraph(struct Node *adj[], int n){
    struct Node *last=NULL;
    for(int i=0; i<n; i++){
        printf("Enter number of neigbours of vertex %d= ",i);
        int k;
        scanf("%d", &k);
        for(int j=1; j<=k; j++){
            printf("Enter neighbour %d= ", j);
            int d;
            scanf("%d", &d);
            printf("Enter cost of edge %d-%d= ", i, d);
            int c;
            scanf("%d", &c);
            struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
            newNode->vertex=d;
            newNode->weight=c;
            newNode->next=NULL;
            if(adj[i]==NULL){
                adj[i]=newNode;
            }
            else{
                last->next=newNode;
            }
            last=newNode;
        }
    }
}
void prim(int n, struct Node *adj[], int src){
    int parent[n], key[n],visited[n], min_cost=0;
    for(int i=0; i<n; i++){
        parent[i]=-1;
        visited[i]=0;
        key[i]=MAX;
    }
    key[src]=0;
    for(int i=0; i<n-1; i++){
        int min_index;
        int min=MAX;
        for(int k=0; k<n; k++){
            if(key[k]<min && visited[k]!=1){
                min_index=k;
                min=key[k];
            }
            
        }
        visited[min_index]=1;
        struct Node *temp=adj[min_index];
        while(temp!=NULL){
            if(visited[temp->vertex]!=1 && temp->weight<key[temp->vertex]){
                key[temp->vertex]=temp->weight;
                parent[temp->vertex]=min_index;
            }
            temp=temp->next;
        }
        // for(int k=0; k<n; k++){
        //     if(cost[min_index][k]!=MAX && visited[k]!=1 && cost[min_index][k]<key[k]){
        //         key[k]=cost[min_index][k];
        //         parent[k]=min_index;
        //     }
        // }
    }
    printf("\nEdge\t Cost\n");
    for(int i=1; i<n; i++){
        struct Node*temp=adj[i];
        while(temp->vertex!=parent[i]){
            temp=temp->next;
        }
        printf("%d-%d %d\n", parent[i], i, temp->weight);
        min_cost+=key[i];
    }
    printf("Total minimum cost= ");
    printf("%d", min_cost);
    
}

void printGraph(struct Node *adj[], int n){
    for(int i=0; i<n; i++){
        printf("Edge\t Cost\n");

        struct Node *temp=adj[i];
        while(temp!=NULL){
            printf("%d-%d\t %d ", i, temp->vertex, temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter number of vertices=\n");
    int n;
    scanf("%d", &n);
    struct Node *adj[n];//= (struct Node*)malloc(n*sizeof(struct Node));
    for(int i=0; i<n; i++){
        adj[i]=NULL;
    }
    readGraph(adj,n);
    printGraph(adj,n);
    printf("Enter source vertex");
    int src;
    scanf("%d", &src);
    prim(n,adj,src);
}