#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; //node will store some data
  struct node *right_child; // right child
  struct node *left_child; // left child
};

//function to create a node
struct node* new_node(int x) {
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left_child = NULL;
  temp -> right_child = NULL;

  return temp;
}   

// insertion
struct node* insert(struct node * root, int x) {
  //searching for the place to insert
  if (root == NULL)
    return new_node(x);
  else if (x > root -> data) // x is greater. Should be inserted to the right
    root -> right_child = insert(root -> right_child, x);
  else // x is smaller and should be inserted to left
    root -> left_child = insert(root -> left_child, x);
  return root;
}

// Recursive Inorder Traversal
void rec_inorder(struct node *root) {
  if (root != NULL) // checking if the root is not null
  {
    rec_inorder(root -> left_child); // traversing left child
    printf(" %d ", root -> data); // printing data at root
    rec_inorder(root -> right_child); // traversing right child
  }
}

////height of the tree
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root->left_child);
    int right_height = height(root->right_child);
    if (left_height > right_height)
    {
        return left_height + 1;
    }
    else
    {
        return right_height + 1;
    }
}

void leafnodes(struct node * root){
    if(root == NULL)
        printf("NULL");
    
    if(root->left_child == NULL && root->right_child == NULL){
        printf("%d ",(root->data));
    }
    
    if(root->left_child)
        leafnodes(root->left_child);
    
    if(root->right_child)
        leafnodes(root->right_child);
}

int main() {
  struct node *root;
  int size;
  int data,tree_height;

  printf("How many nodes do you want?");
  scanf("%d",&size);

  printf("Enter the values: ");
  scanf("%d",&data);
  root = new_node(data);
  for(int i=1;i<size;i++){
    scanf("%d",&data);
    insert(root, data);
  }
 
  
  rec_inorder(root);
  printf("\n");

  printf("\nThe leafnodes are: ");
  leafnodes(root);

  return 0;
}