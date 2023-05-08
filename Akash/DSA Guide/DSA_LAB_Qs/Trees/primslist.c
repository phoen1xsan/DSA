#include<stdio.h>
#include<malloc.h>
struct node{
    int vertex, weight;
    struct node *next;
};

struct node *A[10];

void initialize(struct node *A[], int n){
    for(int i =0;i<n ;i++){
        A[i] = NULL;
    }
}


void create(struct node *A[], int e){
    struct node *new, *P;
    while(e--){
        int v1,v2,w;
        printf("\nEnter edge: ");
        scanf("%d %d",&v1,&v2);
        printf("\nEnter weight: ");
        scanf("%d",&w);


        new = (struct node *)malloc(sizeof(struct node));
        new->vertex = v2;
        new->weight = w;
        new->next = NULL;

        P = A[v1];
        if(P == NULL){
            A[v1] = new;
        }
        else{
            while(P->next !=NULL){
                P = P->next;
            }
            
            P->next = new;
        }

        new = (struct node *)malloc(sizeof(struct node));
        new -> vertex = v1;
        new -> weight = w;
        new->next = NULL;

        P = A[v2];
        if(P == NULL){
            A[v2] = new;
        }
        else{
            while(P->next != NULL){
                P = P->next;
            }
            P->next = new;
        }
    }
}

int closeVertex(int weight[], int visited[], int v){
    int min = 999, index;
    for(int i=0 ;i<v ;i++){
        if(weight[i] < min && visited[i] ==  0){
            min = weight[i];
            index = i;
        }
    }

    return index;
}

void prims(struct node *A[],int weight[], int visited[], int parent[], int v){
   

    for(int i=0;i<v;i++){
        int u = closeVertex(weight,visited,v);   // get the index of the minimum weight that is not visited
        visited[u] = 1;

        struct node *p = A[u];
        while(p!=NULL){
            if(visited[p->vertex] == 0 &&  weight[p->vertex] > p->weight){
                weight[p->vertex] = p->weight;
                parent[p->vertex] = u;
            }

            p = p->next;
        }
    }
}

void Display(int parent[], int weight[], int v){
    printf("\n Parent arr: ");
    int sum =0;
    for(int i=0;i<v;i++){
        printf("%d ",parent[i]);
        sum += weight[i];
    }

    printf("\n Sum of weight: %d", sum);

}
int main(){
    int v,e;
    printf("\nEnter the number of vertices: ");
    scanf("%d" ,&v);
    printf("\nEnter the number of edges: ");
    scanf("%d",&e);
    initialize(A,v);
    create(A,e);
    int weight[v], visited[v], parent[v];
    for(int i=0;i<v;i++){
        weight[i] = 999;
        visited[i] = 0;
        parent[i] = -1;
    }

    weight[0] = 0;
    parent[0] = -1;

    prims(A,weight,visited,parent,v);
    Display(parent,weight,v);
    return 0;
}