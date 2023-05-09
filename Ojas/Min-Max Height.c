#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct stack{
    int size;
    int top;
    int **array;
};

struct node * newnode(int data){
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};

struct node * insert(struct node * root,int data){
    if(root==NULL)
        return newnode(data);
    else if(data<root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

void min_element(struct node * root){
    struct node * temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    printf("%d ",temp->data);
}

void max_element(struct node * root){
    struct node * temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    printf("%d",temp->data);
}

int main(){
    int data,nodes;
    printf("Enter the number of nodes: ");
    scanf("%d",&nodes);

    struct node * root;
    printf("Enter the value of the nodes: ");
    scanf("%d",&data);
    root = newnode(data);

    for(int i=1;i<nodes;i++){
        scanf("%d",&data);
        insert(root,data);
    }
    printf("\nThe minimum element is: ");
    min_element(root);

    printf("\nThe maximum element is: ");
    max_element(root);

    return 0;
}


