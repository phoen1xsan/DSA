#include <stdio.h>

struct emp{
    char name[40];
    int no, sal;
};

void swap(struct emp *x,struct emp *y){
    struct emp temp = *x;
    *x=*y;
    *y=temp; 
}

int SelectionSort(struct emp a[], int n){
    int i,j,k,count=0;

    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(a[j].no<a[k].no){
                k=j;
            }
        }
        swap(&a[i],&a[k]);
        count++;
    }
    return count;
}

void Display(struct emp a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%s %d %d \n", a[i].name, a[i].no, a[i].sal);
    }
}

int main(){
    int n;
    printf("Enter no. of employees: ");
    scanf("%d",&n);
    struct emp a[n];
    printf("Enter employee name , no. and salaray-\n");
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%s %d %d",&a[i].name, &a[i].no,&a[i].sal);
    }

    printf("\n");
    printf("No. of swaps are: %d",SelectionSort(a,n));
    printf("\n");
    printf("Sorted Ascending Order is-\n");
    Display(a,n);

    

    return 0;
}