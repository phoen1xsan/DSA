#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Node
{
    struct Node *left, *right;
    int info;
    bool lthread;
    bool rthread;
};

struct Node *insert(struct Node *root, int ikey)
{
    struct Node *ptr = root;
    struct Node *par = NULL;
    while (ptr != NULL)
    {

        if (ikey == (ptr->info))
        {
            printf("Key already exits!");
            return root;
        }

        par = ptr;
        if (ikey < ptr->info)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }

        else
        {
            if (ptr->rthread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }

    // Create a new node
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp -> info = ikey;
    tmp -> lthread = true;
    tmp -> rthread = true;

    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }

    return root;
}

struct Node *inorderSuccessor(struct Node *ptr)
{

    if (ptr -> rthread == true)
        return ptr->right;


    ptr = ptr -> right;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    return ptr;
}

// Printing the threaded tree
void inorder(struct Node *root)
{
    if (root == NULL)
        printf("Tree is empty");

    // Reach leftmost node
    struct Node *ptr = root;
    while (ptr -> lthread == false)
        ptr = ptr -> left;

    // One by one print successors
    while (ptr != NULL)
    {
        printf("%d ",ptr -> info);
        ptr = inorderSuccessor(ptr);
    }
}

// Driver Program
int main()
{
    struct Node *root = NULL;

    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 199);
    root = insert(root, 147);
    root = insert(root, 13);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 8);

    inorder(root);

    return 0;
}
