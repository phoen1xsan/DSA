#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
    private:
    int front,rear,size;
    Node **Q;
    public:
    Queue(){front=rear=-1;size=10;Q=new Node *[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new Node *[this->size];}
    void enqueue(Node *x);
    Node * dequeue();
    int isEmpty(){return front==rear;}
    void Display();
};

void Queue::enqueue(Node *x){
    if(rear==size-1) cout<<"Queue is full\n";
    else{
        rear++;
        Q[rear]=x;
    }
}

Node * Queue::dequeue(){
    Node* x=NULL;
    if(rear==front) cout<<"Queue is empty\n";
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::Display(){
    for(int i =front+1;i<=rear;i++){
        printf("%d ",Q[i]);
    }
    printf("\n");
}