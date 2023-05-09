#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node * prev;
   struct node * next;
};
struct node * head, * last;  


struct node * create(int size){
   struct node * temp;
   int data;

   head = (struct node *)malloc(sizeof(struct node));

  if(size >= 1){
   printf("Enter the data for node 1: ");
   scanf("%d",&(head->data));
   head ->next = NULL;
   head ->prev = NULL;
   last = head;

   for(int i=2;i<=size;i++){
      temp = (struct node *)malloc(sizeof(struct node));
      printf("Enter the data for node %d: ",i);
      scanf("%d",&data);
      temp->data = data;
      temp->next = NULL;
      last ->next = temp;
      temp->prev = last;
      last = temp;
   }
  }
  else{
   printf("No mmemory allocated");
  }
}

void display(){
   struct node * ptr;
   ptr = head;
   while(ptr!=NULL){
      printf("%d <=> ",ptr->data);
      ptr = ptr->next;
   }
   printf("NULL");
}

int main(){
   struct node * ptr;
   printf("Enter the number of nodes: ");
   int n;
   scanf("%d",&n);
   create(n);
   display();
   return 0;
}