#include<stdio.h>
#include<stdlib.h>

//creating the structure
struct node{
    int data;
    struct node * next;
    struct node * prev;
}* head, * last;

//function to display the linked list
void display(){
    struct node * ptr = head;
    while(ptr != NULL){
        printf("%d <=>",(ptr->data));
        ptr = ptr ->next;
    }
    printf("NULL");
}

//function to insert into the linked list
void insert(int size){
    struct node * new;
    struct node * temp;
    struct node * later;
    temp = head;

    //creating a new node
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value for the new node: ");
    scanf("%d",&(new->data));
    new->next = NULL;
    new->prev = NULL;

    //position of the new node
    printf("Enter the position for the new node: ");
    int pos;
    scanf("%d",&pos);

    //insert at the start
    if(pos == 1){
        temp ->prev =new;
        new->next = temp;
        head = new;;
    }
    //insert at the end
    else if(pos == size){
        while(temp -> next != NULL){
            temp = temp->next;
        }
        last = temp;
        last -> next = new;
        new ->prev = last;
        last = new;
    }

    //insert in between 
    else{
        for(int i=1;i<pos-1;i++){
            temp = temp->next;
        }
        later = temp->next;
        temp->next = new;
        new->prev = temp;
        new->next = later;
        later->prev = new;

    }

    display();
}

//function to creating the linked list
void create(int size){
    
    struct node * new;
    //creating the head node
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node 1: ");
    scanf("%d",&(head->data));
    head->next = NULL;
    head->prev = NULL;
    last = head;
    last->next = NULL;
    last->prev = NULL;

    //creating the other nodes
    for(int i=2;i<=size;i++){
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ",i);
        scanf("%d",&(new->data));
        new -> next = NULL;
        new -> prev = NULL;
        last ->next = new;
        new->prev = last;
        last = new;
    }

    display();

}

//driver code
int main(){
    printf("Enter the size of the linkedlist: ");
    int size;
    scanf("%d",&size);
    
    //creating the linked list
    create(size);
    
    //inserting the nodes
    insert(size);


    return 0;
}