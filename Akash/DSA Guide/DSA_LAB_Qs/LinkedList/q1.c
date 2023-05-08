#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
}
*first =NULL;

void create(int A[], int n){
    struct node * last, * t;
    first = (struct node *)malloc(sizeof(struct node));
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

int count(struct node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void FrontBackSplit(struct node *p, int n){
    if(n==0){
        printf("Main list is empty\n");
        return;
    }
    int c=count(p);
    int split = c/2;
    int i;
    printf("First list is-\n");
    if(c%2!=0){
        for(i=0;i<=split;i++){
            printf("%d ",p->data);
            p=p->next;
        }
    }
    else{
        for(i=0;i<split;i++){
            printf("%d ",p->data);
            p=p->next;
        }
    }
    printf("\nSecond list is-\n");
    for(;i<n;i++){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[]={};
    create(A, 0);
    FrontBackSplit(first,0);
    return 0;
}