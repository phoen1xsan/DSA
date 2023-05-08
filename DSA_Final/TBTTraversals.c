#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    int lbit;
    int rbit;
    struct node* left;
    struct node* right;
    struct node* parent;
};

typedef struct node node;

node* createNode(char data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->lbit = 0;
    newNode->rbit = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}


node* insert(node* root, char data){
    if(root == NULL){
        return createNode(data);
    }
    node* temp = root;
    node* parent = NULL;
    while(1){
        if(data < temp->data){
            if(temp->lbit == 0){
                node* newNode = createNode(data);
                newNode->left = temp->left;
                newNode->right = temp;
                newNode->parent = temp;
                temp->lbit = 1;
                temp->left = newNode;
                return root;
            }
            else{
                parent = temp;
                temp = temp->left;
            }
        }
        else{
            if(temp->rbit == 0){
                node* newNode = createNode(data);
                newNode->right = temp->right;
                newNode->left = temp;
                newNode->parent = temp;
                temp->rbit = 1;
                temp->right = newNode;
                return root;
            }
            else{
                parent = temp;
                temp = temp->right;
            }
        }
    }
}


void postorderTBT(node* root) {
    node* temp = root;
    node* lastVisited = NULL;
    while (temp->lbit == 1) {
        temp = temp->left;
    }
    while (temp != NULL) {
        if (temp->rbit == 0 || temp->right == lastVisited) {
            printf("%c ", temp->data);
            lastVisited = temp;
            temp = temp->parent;
        }
        else {
            temp = temp->right;
            while (temp->lbit == 1) {
                temp = temp->left;
            }
        }
    }
}

void inorderTBT(node* root){
    node* temp = root;
    while(temp->lbit == 1){
        temp = temp->left;
    }
    while(temp != NULL){
        printf("%c ", temp->data);
        if(temp->rbit == 0){
            temp = temp->right;
        }
        else{
            temp = temp->right;
            while(temp->lbit == 1){
                temp = temp->left;
            }
        }
    }
}

void preorderTBT(node* root){
    node* temp = root;
    while(temp != NULL){
        printf("%c ", temp->data);
        if(temp->lbit == 1){
            temp = temp->left;
        }
        else if(temp->rbit == 1){
            temp = temp->right;
        }
        else{
            while(temp != NULL && temp->rbit == 0){
                temp = temp->right;
            }
            if(temp != NULL){
                temp = temp->right;
            }
        }
    }
}

int main(){
    node* root = NULL;
    root = insert(root, 'F');
    root = insert(root, 'C');
    root = insert(root, 'Q');
    root = insert(root, 'A');
    root = insert(root, 'D');
    root = insert(root, 'H');
    root = insert(root, 'K');

// Input Tree taken is:
//          F
//       /     \
//      C       Q
//     / \     /
//    A   D   H
//             \
//              K

    printf("Inorder traversal: ");
    inorderTBT(root);
    printf("\nPreorder traversal: ");
    preorderTBT(root);
    printf("\nPostorder traversal: ");
    postorderTBT(root);
    return 0;
}
