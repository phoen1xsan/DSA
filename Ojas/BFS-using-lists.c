#include<stdio.h>
#include<stdlib.h>

int vertices;

struct node{
int data;
struct node * next;
};

void readGraph(struct node *adj[]){
    struct node * newnode, * last;
    int k,data;
    for(int i=0;i<vertices;i++){
        printf("Enter the number of neighbours for node %d: ",i);
        scanf("%d",&k);

        for(int j=1;j<=k;j++){
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Neighbour %d of node %d: ",j,i);
            scanf("%d",&data);
            newnode->data = data;
            newnode->next = NULL;

            if(adj[i] == NULL){
                adj[i] = newnode;
            }
            else{
                last -> next = newnode;
            }
            last = newnode;
        }
    }
}

void printGraph(struct node * adj[]){
    struct node * temp;
    for(int i=0;i<vertices;i++){
            temp = adj[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void bfs(struct node *adj[],int visited[],int start){
   int queue[vertices],front=-1,rear=-1;
   queue[++rear] = 0;
   front ++;
   struct node * ptr;

   while(front<=rear){
    start = queue[front++];
    ptr = adj[start];
    visited[start] = 1;
    printf("%d\t",start);
    while(ptr!=NULL){
        if(visited[ptr->data] != 1){
            queue[++rear] = ptr->data;
            visited[ptr->data] = 1;
        }
        ptr = ptr->next;
    }
   }

}

int main(){

    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);

    struct node * adj[vertices];

    for(int i=0;i<vertices;i++){
        adj[i] = NULL;
    }

    readGraph(adj);
//    printGraph(adj);

    int start,visited[vertices];
    printf("Enter which vertex you want to start: ");
    scanf("%d",&start);

    for(int i=0;i<vertices;i++){
        visited[i] = 0;
    }

    bfs(adj,visited,start);
}
