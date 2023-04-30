#include <iostream>
#include<stdlib.h>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){

    cout<<"Enter size of stack";
    cin>>st->size;
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));

}

void Display(struct Stack st){

    int i;
    for ( i = st.top; i >= 0; i--)
    {
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
    
}

void push(struct Stack *st, int x){
    
    if(st->top==st->size-1) cout<<"Stack overflow\n";
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1) cout<<"Stack underflow\n";
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index){
    int x=-1;
    if(st.top-index+1<0) cout<<"Invalid index"<<endl;
    x=st.S[st.top-index+1];
    return x;

}

int isEmpty(struct Stack st){
    if(st.top==-1) return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.top==st.size-1) return 1;
    return 0;
}

int stackTop(struct Stack st){
    if(st.top!=-1) return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,4);
    push(&st,9);
    push(&st,99);
    cout<<stackTop(st)<<endl;
    Display(st);
    
    return 0;
}
