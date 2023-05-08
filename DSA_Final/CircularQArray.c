#include<stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x){
   if((front == 0 && rear == MAX-1) || (front == rear+1)){
      printf("\nQueue Overflow\n");
   }
   else{
      if(front == -1){
         front = 0;
      }
      rear = (rear+1)%MAX;
      queue[rear] = x;
      printf("\nInserted element is: %d",x);
   }
}

void dequeue(){
   if(front == -1){
      printf("\nQueue Underflow\n");
   }
   else{
      printf("\nDeleted element is: %d",queue[front]);
      if(front == rear){
         front = -1;
         rear = -1;
      }
      else{
         front = (front+1)%MAX;
      }
   }
}

void display(){
   int i;
   if(front == -1){
      printf("\nQueue is empty\n");
   }
   else{
      printf("\nQueue elements are:\n");
      if(front <= rear){
         for(i=front; i<=rear; i++){
            printf("%d\t",queue[i]);
         }
      }
      else{
         for(i=front; i<MAX; i++){
            printf("%d\t",queue[i]);
         }
         for(i=0; i<=rear; i++){
            printf("%d\t",queue[i]);
         }
      }
   }
}

int main(){
   int ch, val;
   do{
      printf("\n1. Enqueue");
      printf("\n2. Dequeue");
      printf("\n3. Display");
      printf("\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch){
         case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&val);
            enqueue(val);
            break;
         case 2:
            dequeue();
            break;
         case 3:
            display();
            break;
         case 4:
            printf("\nExit\n");
            break;
         default:
            printf("\nInvalid Choice\n");
      }
   }while(ch!=4);
   return 0;
}
