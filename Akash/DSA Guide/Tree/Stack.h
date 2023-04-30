#include <iostream>
#include<stdlib.h>
using namespace std;

struct Stack{
    int size;
    int top;
    struct Node  **S;
};

void Stackcreate(struct Stack *st, int size){

    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node *));

}

void push(struct Stack *st, struct Node *x){
    
    if(st->top==st->size-1) cout<<"Stack overflow\n";
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st){
    struct Node *x=NULL;
    if(st->top==-1) cout<<"Stack underflow\n";
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}


int isEmptyStack(struct Stack st){
    if(st.top==-1) return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.top==st.size-1) return 1;
    return 0;
}


