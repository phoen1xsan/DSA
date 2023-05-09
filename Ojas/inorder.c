#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct stack{
    int top;
    int size;
    struct stack **array;
};

struct node * newnode(int data){
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp ->left = temp->right = NULL;
    return temp;
};

struct node * insert(struct node * root,int data){
    if(root == NULL)
        return newnode(data);
    else if(data<root->data){
        root->left = insert(root->left,data);
    }
    else if(data>root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

int isEmpty(struct stack * stack){
    return stack->top == -1;
}

int isFull(struct stack * stack){
    return stack->top -1 == stack->size;
}

void push(struct node * temp,struct stack * stack){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = temp;
}

struct node * pop(struct stack * stack){
    if(isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct stack * createStack(int size){
    struct stack * stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->size = size;
    stack->array = (struct node **)malloc(stack->size * sizeof(struct node *));
    return stack;
}


void inorder(struct node * root){
    if(root == NULL)
        return;
    else{
        struct node * temp = root;
        struct stack * stack = createStack(MAXSIZE);
        while(temp!=NULL){
            push(temp,stack);
            temp=temp->left;
        }
        while(!isEmpty(stack)){
            temp = pop(stack);
            printf("%d ",temp->data);
            temp = temp->right;
                while(temp!=NULL){
                push(temp,stack);
                temp=temp->left;
            }
        }
    }
}


int main(){
int nodes,data;
printf("Enter the number of nodes: ");
scanf("%d",&nodes);

struct node * root = NULL;
printf("Enter the value of the nodes: ");
scanf("%d",&data);
root = newnode(data);

for(int i=1;i<nodes;i++){
    scanf("%d",&data);
    insert(root,data);
}


printf("\nThe tree is: ");
inorder(root);

return 0;
}
