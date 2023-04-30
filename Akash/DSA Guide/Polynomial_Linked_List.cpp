#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create(){
    struct Node *t, *last;
    int i, num;
    cout<<"Enter number of terms";
    cin>>num;
    cout<<"Enter each term with coeff and exp"<<" ";

    for ( i = 0; i < num; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL){
            poly = last = t;
        }
        else
        {
            last->next=t;
            last=t;
        }
        
    }
    
}

void Display(struct Node *p){
    while(p){
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<endl;
}

long eval(struct Node*p, int x){
    long s = 0;
    while (p)
    {
        s+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return s;
}

int main()
{
    create();
    Display(poly);
    cout<<eval(poly,1);
    return 0;
}
