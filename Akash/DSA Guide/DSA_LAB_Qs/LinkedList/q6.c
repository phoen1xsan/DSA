#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * first, *head,*tail;

void create(int A[], int n){

    struct node *t, * last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    int i;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }


}

struct node * CopyList(struct node * p){

    head=(struct node*)malloc(sizeof(struct node));
    struct node * temp,* q;
    head->data=p->data;
    head->next=NULL;
    temp=head;
    p=p->next;

    while(p!=NULL){
        q=(struct node *)malloc(sizeof(struct node));
        q->data=p->data;
        q->next=NULL;
        temp->next=q;
        temp=q;
        p=p->next;
    }

    return head;
}

void Display(struct node * p){
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    
    int A[]={1,2,3,4,5};
    create(A,5);

    struct node * r=CopyList(first);
    Display(r);

    return 0;
}