#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{   // Basic node structure
    int data;
    struct Node * next = NULL;
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

void Display(struct Node *p){   // Fn to display linked list
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void Rdisplay(struct Node *p){   // Recursive display of linked list
    if(p!=NULL){
        Rdisplay(p->next);
        cout<<p->data<<" ";
    }
}

int Count(struct Node *p){   // Count no. of nodes in linked list
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int Rcount(struct Node *p){   // Recursive count
    if(p) return Rcount(p->next)+1;
    else return 0;
}

int Sum(struct Node *p){   // Sum of data elements of linked list
    int s = 0;
    while(p){
        s = s + p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p){   // Recursive sum
    if(p) return Rsum(p->next) + p->data;
    else return 0;
}

int Maxe(struct Node *p){   // Max element
    int maxi = p->data;
    while(p){
        if(p->data > maxi) maxi = p->data;
        p=p->next;
    }
    return maxi;
}

int Rmaxe(struct Node *p){   // Recursive max
    int x =0;
    if(p==0) return INT32_MIN;
    x = Rmaxe(p->next);
    if(x>p->data) return x;
    else return p->data;
}

struct Node *  Lsearch(struct Node *p, int key){   // Linear search 
    while(p){
        if(p->data == key) return p;
        p=p->next;
    }
    return NULL;
}

struct Node * Rlsearch(struct Node *p, int key){   // Recursive L search
    if(p==NULL) return NULL;
    if(p->data == key) return p;
    Rlsearch(p->next,key);
}

struct Node *  Adv_lsearch(struct Node *p, int key){  // Move to head linear search
    struct Node *q;
    while(p){
        if((p->data == key) && (p==first)) return p;
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x){ // To insert a node at a given pos
    struct Node *t;
    int i;

    if(index<0 || index>Count(p)) return ;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}

void SortedInsert(struct Node *p, int x){ // To insert in a sorted linked list
    struct Node *t, *q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next = NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index){ // To delete a node
    struct Node *q=NULL;
    int x=-1,i;
    if(index<1 || index>Count(p)){
        return x;
    }
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for ( i = 0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        free(p);
        return x;
        
    }
}

int Issorted(struct Node *p){
    int x = INT32_MIN;
    while (p)
    {
        if (p->data<x) return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
    
}

void removeSortedDuplicates(struct Node *p){
    struct Node *q = p->next;
    while (q)
    {
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
    
}

void Reverse1(struct Node *p){
    struct Node *q=p;
    int *A,i=0;
    A = (int *)malloc(sizeof(int)*Count(p));

    while (q!=NULL)
    {
        A[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        i--;
        q=q->next;
    }
}

void Reverse2(struct Node *p){
    struct Node *q=NULL, *r=NULL;

    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
    
}

void Reverse3(struct Node *q, struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next=q;
    }
    else first = q;
}

void Concat(struct Node *p, struct Node*q){
    third=p;
    while (p->next)
    {
        p=p->next;
    }
    p->next=q;
    
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while (p && q)
    {
        if(p->data < q->data){
            last->next=p;
            last = p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last = q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
    
}

int isLoop(struct Node *f){
    struct Node *p, *q;
    p=q=f;

    do{
        p=p->next;
        q=q->next;
        q = q!=NULL?q->next:q;
    }while(p && q && p!=q);

    if(p==q) return 1;
    else return 0;
}

int main(){
    int A[] = {1,2,4};
    create(A,3);
    
    return 0;
}
