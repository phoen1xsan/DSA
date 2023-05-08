#include <stdio.h>
#include <malloc.h>

struct Node{   // Basic node structure
    int data;
    struct Node * next;
}

*first = NULL, *second=NULL, *third=NULL;

void create1(int A[], int n){   // Fn to create a linked list
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

void create2(int A[], int n){   // Fn to create a linked list
    struct Node * t, * last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    int i;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Append(struct Node *p, struct Node * q){
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    q=NULL;
}

void Display(struct Node * p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={1,3,5,7,9};
    create1(A,5);
    int B[]={2,4,6,8,10};
    create2(B,5);

    Append(first,second);

    Display(first);
}