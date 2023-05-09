#include<stdio.h>
#include<stdlib.h>
#define MAX 999

struct Node{
    int vertex;
    int weight;
    struct Node *next;
};

void readGraph(int n, struct Node *adj[]){
    struct Node* last= NULL;
    for(int i=0; i<n; i++){
    printf("Enter number of neighbours of vertex %d= ", i);
    int x;
    scanf("%d", &x);
    for(int k=0; k<x; k++){
        printf("Enter neighbour %d= ", k+1);
        int j,c;
        scanf("%d", &j);
        printf("Enter cost of the edge %d-%d= ",i,j);
        scanf("%d", &c);
        struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->next=NULL;
        newNode->vertex=j;
        newNode->weight=c;
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

void printGraph(struct Node *adj[], int n){
    printf("Edge\t Cost\n");
    for(int i=0; i<n; i++){
    struct Node *temp=adj[i];
    while(temp!=NULL){
    printf("%d-%d\t%d\n",i,temp->vertex,temp->weight);
    temp=temp->next;
    }
    }
}

void dijkstra(int n, struct Node *adj[], int src){
    int visited[n], dist[n];
    for(int i=0; i<n; i++){
        visited[i]=0;
        dist[i]=MAX;
    }

    dist[src]=0;
    for(int i=0; i<n-1; i++){
        int min_index, min_dist=MAX;
        for(int x=0; x<n; x++){
            if(visited[x]!=1 && dist[x]<min_dist){
                min_dist=dist[x];
                min_index=x;
            }
        }
        visited[min_index]=1;
        struct Node *temp=adj[min_index];
        while(temp!=NULL){
            if(visited[temp->vertex]!=1 && dist[min_index]!=MAX && dist[min_index]+temp->weight<dist[temp->vertex]){
                dist[temp->vertex]=dist[min_index]+temp->weight;
            }
            temp=temp->next;
        }
    }

    printf("Vertex\t Minimum Distance from Source\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\n",i,dist[i]);
    }


}

int main(){
    printf("Enter number of vertices=\n");
    int n;
    scanf("%d", &n);
    struct Node *adj[n];
    for(int i=0; i<n; i++){
        adj[i]=NULL;
    }
    readGraph(n, adj);
    printGraph(adj,n);
    printf("Enter the source vertex: ");
    int src;
    scanf("%d",&src);
    dijkstra(n,adj,src);
}
