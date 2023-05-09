#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void create(int size){
    struct node * temp;

    //alocating memory for head
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for node 1: ");
    scanf("%d",&(head->data));
    head -> prev = NULL;
    head -> next = NULL;

    last = head;
    last -> next = NULL;
    last -> prev = NULL;
    //allocating other nodes
    for(int i=2;i<=size;i++){
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ",i);
        scanf("%d",&(temp->data));
        temp->next = NULL;
        temp->prev = last;
        last ->next = temp;
        last = temp;
    }

}

void display(){
    printf("The linkedlist is: ");
    struct node * ptr = head;
    while(ptr != NULL){
        printf("%d <=>",(ptr->data));
        ptr = ptr->next;
    }
    printf("NULL");
}

void delete(int num,int size){

    struct node * temp= head;
    if(num==1){
    head = head->next;
    free(temp);
    }

    else if(num==size){
        struct node * del;
      while(temp -> next ->next !=NULL){
        temp = temp ->next;
      }
      del = temp->next;
      temp->next = NULL;
      del->prev = NULL;
      free(del);
     
      
    }

    else{

    
    struct node * del;
    struct node * later;
    for(int i=2;i<num;i++){
        temp = temp->next;
    }
    del = temp->next;
    later = temp->next->next;
    temp ->next = later;
    later->prev = temp;
    free(del);

    }
    

}


int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    create(n);
    display();

    printf("\n\nWhich node do you want to delete: ");
    int node_del;
    scanf("%d",&node_del);

    delete(node_del,n);
    display();

    
    return 0;
}