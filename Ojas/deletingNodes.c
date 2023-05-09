#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int x){
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->left = temp->right = NULL;

    return temp;
}

struct node * insert(struct node * root,int x){
    if(root == NULL)
        return newnode(x);
    else if(x<root->data){
        root->left = insert(root->left,x);
    }
    else{
        root->right = insert(root->right,x);
    }

    return root;
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",(root->data));
        inorder(root->right);
    }
}

struct node * minNodeValue(struct node * root){
    struct node * current = root;

    while(current && current->left != NULL)
        current = current -> left;
}

struct node *deletenode(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deletenode (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletenode (root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = root;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deletenode (root->right, temp->data);
    }
    return root;
}




int main(){
    struct node * root;
    struct node * delete;
    int size;
    printf("Enter the number of nodes: ");
    scanf("%d",&size);

    int data;
    printf("Enter the data for the nodes: ");
    scanf("%d",&data);

    root = newnode(data);

    for(int i=1;i<size;i++){
        scanf("%d",&data);
        insert(root,data);
    }

    printf("\n");
    printf("The tree is: ");
    inorder(root);

    int node_delete;
    printf("\n\nEnter which node to delete: ");
    scanf("%d",&node_delete);
    delete = deletenode(root,node_delete);
    printf("The tree is: ");
    inorder(delete);

    return 0;
}