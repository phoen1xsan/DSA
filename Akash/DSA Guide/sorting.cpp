#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void swap(int *x,int *y){
    int temp =*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[], int n){
    int i,j,flag=0;
    for ( i = 0; i < n-1; i++){
        flag=0;
        for ( j = 0; j < n-1-i; j++)
        {
            if (A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
            
        }
        
    }
}

void Insertion(int A[],int n){
    int i,j,x;
    for ( i = 1; i < n; i++)
    {
        j=i-1;
        x=A[i];
        while (j!=-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void SelectionSort(int A[],int n){
    int i , j, k;
    for(i=0;i<n-1;i++){
        for ( j = k = i; j < n; j++)
        {
            if (A[j]<A[k])
            {
                k=j;
            }
            
        }
        swap(&A[i],&A[k]);
    }
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i=l,j=h;
    do
    {
        do
        {
            i++;
        } while(A[i]<=pivot);

        do
        {
            j--;
        } while (A[j]>pivot);

        if (i<j)
        {
            swap(&A[i],&A[j]);
        }
        
        
    } while (i<j);
    swap(&A[l],&A[j]);
    return j;
    
}

void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

void Merge(int A[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int B[100];
    while (i<=mid && j<=h)
    {
        if (A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
        
    }
    for(;i<=mid;i++){
        B[k++]=A[i];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(int i =l;i<=h;i++){
        A[i]=B[i];
    }
    
}

void IMergeSort(int A[], int n){
    int i, p , l, mid, h;
    for ( p = 2; p <=n; p=p*2)
    {
        for ( i = 0; i+p-1<n; i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
        
    }
    if ((p/2)<n)
    {
        Merge(A,0,p/2-1,n-1);
    }
    
    
}

void RMergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        RMergeSort(A, l,mid);
        RMergeSort(A,mid + 1, h);
        Merge(A,l,mid,h);
    }
}

int findMax(int A[], int n){
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i]>max)
        {
            max = A[i];
        }       
    }
    return max;
    
}

void CoutSort(int A[], int n){
    int i , j, *c;
    int max = findMax(A, n);
    c = (int *)malloc(sizeof(int)*(max + 1));

    for(i = 0;i<max +1;i++){
        c[i]=0;
    }
    for ( i = 0; i < n; i++)
    {
        c[A[i]]++;
    }
    i=0, j=0;
    while (j<max +1)
    {
        if (c[j]>0)
        {
            A[i++]= j;
            c[j]--;
        }
        else{
            j++;
        }
        
    }
    
    
}

void ShellSort(int A[], int n){
    for (int gap = n/2; gap > 0; gap = gap/2)
    {
        for (int i = gap; i < n; i+=gap)
        {
            for (int j = i; j>0; j-=gap)
            {
                if (A[j]<A[j-gap])
                {
                    swap(&A[j],&A[j-gap]);
                }
                else{
                    break;
                }
                
            }
            
        }
        
    }
    
}

int main(){
    int A[]={25,9,8,7,6,1,2,3,4,5},n=10,i;
    ShellSort(A,n);
    for(i=0;i<10;i++){
        printf("%d ",A[i]);
    }
}