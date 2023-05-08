#include <stdio.h>
#include <malloc.h>

struct Node{   // Basic node structure
    int data;
    struct Node * next;
}

*first = NULL, *second=NULL, *third=NULL;

void create(int A[], int n){   // Fn to create a linked list
    struct Node * t, * last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    int i;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Reverse(struct Node * p){
    struct Node * q=NULL, *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Display(struct Node * p){
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    Reverse(first);
    Display(first);
}