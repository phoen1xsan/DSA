#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    if(n!=1){
        Head->next=NULL;
        last = Head;
        for ( i = 1; i < n; i++)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
        t->next=Head;
    }

    if(n==1) Head->next=Head;  
}

void Display(struct Node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=Head);
    cout<<endl;
}

void RDisplay(struct Node *h){
    static int flag=0;
    if(h!=Head || flag!=1){
        flag=1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag=0;
}

int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void Insert(struct Node *p,int index, int x){
    struct Node *t;
    int i;
    if(index<0 || index>Length(p)) return ;
    if(index==0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(Head==NULL){
            Head = t;
            Head->next=Head;

        }
        else{
            while(p->next!=Head) p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else{
        for(i=0;i<index-1;i++)p=p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int Delete(struct Node*p, int index){
    if(index<=0 || index>Length(p)) return -1;
    int i,x;
    struct Node *q;
    if(index==1){
        while(p->next!=Head) p=p->next;
        if(p==Head){
            free(p);
            Head=NULL;
        }
        else{
            q=p->next;
            x=q->data;
            p->next=q->next;
            free(q);
            Head=p->next;
            return x;
        }
    }
    else{
        for(i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        x=q->data;
        p->next=q->next;
        free(q);
        return x;
    }

} 

int main(){

    int A[]={2,3,4,5,6};
    create(A,5);
    Delete(Head,0);
    Display(Head);
    return 0;
}