#include <stdio.h>
#include <stdlib.h>

struct Node{   // Basic node structure
    int data;
    struct Node * next;
}

*first = NULL;

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

void Display(struct Node *p){   // Fn to display linked list
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
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

void Reverse(struct Node *p){
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

int main(){
    int A[] = {1,2,4,5,6};

    printf("Creating a linked list: ");
    create(A,5);
    Display(first);
    printf("\n\n");

    printf("Inserting in  a linked list: ");
    Insert(first,1,9);
    Display(first);
    printf("\n\n");

    printf("Deleting in a linked list: ");
    Delete(first,2);
    Display(first);
    printf("\n\n");

    printf("Reversing a linked list: ");
    Reverse(first);
    Display(first);
    printf("\n\n");

    return 0;
}
