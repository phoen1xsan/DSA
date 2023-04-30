#include <iostream>
using namespace std;

class Queue{
    private:
    int front,rear,size, *Q;
    public:
    Queue(){front=rear=-1;size=10;Q=new int[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x){
    if(rear==size-1) cout<<"Queue is full\n";
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
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

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    printf("%d\n",q.dequeue());
    q.Display();
    return 0;
}
