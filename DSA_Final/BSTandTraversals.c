#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(TreeNode** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

void levelOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    printf("\n");
}

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;

    while (true) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (top == -1) {
            break;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }

    printf("\n");
}

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        TreeNode* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }

        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }

    printf("\n");
}

void postorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;
    TreeNode* prev = NULL;

    while (top != -1) {
        TreeNode* current = stack[top];

        if (prev == NULL || prev->left == current || prev->right == current) {
            if (current->left != NULL) {
                stack[++top] = current->left;
            }
            else if (current->right != NULL) {
                stack[++top] = current->right;
            }
        }
        else if (current->left == prev) {
            if (current->right != NULL) {
                stack[++top] = current->right;
            }
        }
        else {
            printf("%d ", current->data);
            top--;
        }

        prev = current;
    }

    printf("\n");
}

int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int height = 0;
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        height++;

        while (levelSize > 0) {
            TreeNode* current = queue[front++];
            levelSize--;

            if (current->left != NULL) {
                queue[rear++] = current->left;
            }

            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
    }

    return height;
}

int countLeafNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void mirror(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    mirror(root->left);
    mirror(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    TreeNode* root = NULL;

    // Insert some nodes into the tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 9);

    printf("Level-wise Traversal: ");
    levelOrder(root);

    int height = getHeight(root);
    printf("Height of tree: %d\n", height);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("Postorder Traversal: ");
    postorder(root);

    int numLeafNodes = countLeafNodes(root);
    printf("Number of Leaf Nodes: %d\n", numLeafNodes);

    mirror(root);

    printf("Level-wise Traversal (Mirrored): ");
    levelOrder(root);

return 0;
}
