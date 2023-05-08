#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node* createNode(int key) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct node* find(struct node* root, int key) {
    while (root != NULL) {
        if (key == root->key) {
            return root;
        } else if (key < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

struct node* findMin(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* delete(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key < root->key) {
        root->left = delete(root->left, key);
    } else if (key > root->key) {
        root->right = delete(root->right, key);
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            struct node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find\n");
        printf("4. Show\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to be inserted: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to be deleted: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                printf("Enter key to be found: ");
                scanf("%d", &key);
                if (find(root, key) == NULL) {
                printf("Key not found in the tree\n");
                } else {
                printf("Key found in the tree\n");
                }
                break;
            case 4:
            printf("Binary Search Tree: ");
            inorder(root);
            printf("\n");
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
