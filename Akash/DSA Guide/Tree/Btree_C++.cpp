#include <iostream>
#include <stdio.h>
#include "Queue1.h"

class Tree{
    Node *root;  //this is private root
    public:
    //Node *root;
    Tree(){root=NULL;}
    void CreateTree();
    void preorder(){preorder(root);}// dummy fn in case u make root private
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
};

void Tree::CreateTree(){
    Node *p,*t;
    int x;
    Queue q(100);
    printf("Enter root value ");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p=q.dequeue();
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);

    }
}

void Tree::inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);

    }
}

void Tree::postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);

    }
}


int main()
{
    Tree t;
    t.CreateTree();
    cout<<"Preorder ";
    t.preorder();
    cout<<endl;
    cout<<"Inorder ";
    //t.inorder(t.root);
    cout<<endl;
    return 0;
}
