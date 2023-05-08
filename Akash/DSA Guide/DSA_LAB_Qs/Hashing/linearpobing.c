#include <stdio.h>
#include <conio.h>
#define SIZE 10              /* size of the hash table*/
#define FALSE 0
#define TRUE 1
#define h(x) x%SIZE         /*hashing function */
void insert( int data[],int flag[],int chain[],int x);
int search(int data[],int flag[],int chain[],int x);
void print(int data[],int flag[],int chain[]);

void main()
 {
    int data[SIZE],flag[SIZE],chain[SIZE],i,j,x,op,loc;
    /* array data[]  - is a hash table
    array flag[]  - if flag[i] is 1 then the ith place of the hash
              table is filled
    array chain[]- for chaining of synonyms */
    for(i=0;i<SIZE;i++) /* initialize */
       {
        flag[i]=FALSE;
        chain[i]=-1;
       }
    clrscr();
    do
       {
        flushall();
        printf("\n\n1)Insert\n2)Search\n3)Print\n4)Quit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&op);
        switch(op)
           {
            case 1: printf("\n Enter a number to be inserted:");
                scanf("%d",&x);
                insert(data,flag,chain,x);
                break;
            case 2: printf("\n Enter a number to be searched :");
                scanf("%d",&x);
                if((loc=search(data,flag,chain,x))==-1)
                    printf("\n****Element not found****");
                else
                    printf("\n***Found at the location=%d",loc);
                break;
            case 3: print(data,flag,chain);
                break;
           }
    }while(op!=4);
  }

void insert( int data[],int flag[],int chain[],int x)
{
    int i=0,j,start;
    start=h(x); /*hashed location*/
    /*locate the beginning of the chain*/
    while(flag[start] && i<SIZE)
       {
        if(data[start]%SIZE==x%SIZE)
            break;
        i++;
        start=(start+1)%SIZE;
       }
    if(i==SIZE)
       {
        printf("\n***hash table is full****");
        return;
       }
    /*go to the end of chain */
    while(chain[start]!=-1)
        start=chain[start];
    /*locate an empty place for the current data */
    j=start;
    while(flag[j] && i<SIZE)
      {
        j=(j+1)%SIZE;
        i=i+1;
      }
    if(i==SIZE)
      {
        printf("\n***hash table is full****");
        return;
      }
    data[j]=x;   /*store the data */
    flag[j]=TRUE;
    if(j!=start)
        chain[start]=j; /*set the chain */
}

int search(int data[],int flag[],int chain[],int x)
 {
    int i=0,j;
    j=h(x); /*hashed location*/
    /*locate beginning of the chain*/
    while(i<SIZE && flag[j] && data[j]%SIZE !=x%SIZE)
       {
        i++;
        j=(j+1)%SIZE;
       }
    if(!flag[j] || i==SIZE)
        return(-1);
    /*locate the element in the chain */
    while(j!=-1)
       {
        if(data[j]==x)
            return(j);
        j=chain[j];
       }
    return(-1);
}

void print(int data[],int flag[],int chain[])
 {
    int i;
    for(i=0;i<SIZE;i++)
        if(flag[i])
            printf("\n(%d) %d     %d",i,data[i],chain[i]);
        else
            printf("\n(%d) ---    %d",i,chain[i]);
 }