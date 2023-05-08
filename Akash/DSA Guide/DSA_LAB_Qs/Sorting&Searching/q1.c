#include <stdio.h>

struct stud
{
    char name[30];
    int roll, total_marks;
};



void swap(struct stud * x, struct stud * y){
    struct stud temp=*x;
    *x=*y;
    *y=temp;
}

int BubbleSort(struct stud arr[], int n){
    int i,j, count=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if (arr[j].roll>arr[j+1].roll)
            {
                count++;
                swap(&arr[j],&arr[j+1]);
            }
            
        }
    }
    return count;
}

static int count = 0;

int Partition(struct stud A[], int l, int h){
    struct stud pivot = A[l];
    int i=l,j=h;
    do{
        do{
            i++;
        }while(A[i].roll<=pivot.roll);

        do{
            j--;
        }while(A[j].roll>pivot.roll);
        if(i<j){
            swap(&A[i],&A[j]);
            count++;
        }
    }while(i<j);
    swap(&A[l],&A[j]);
    count++;
    return j;
}

void QuickSort(struct stud A[], int l, int h){
    int j;
    if(l<h){
        j=Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

void Display(struct stud arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%s %d %d",arr[i].name, arr[i].roll, arr[i].total_marks);
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter the no. of students: ");
    scanf("%d",&n);

    struct stud arr[n];
    int i=0;
    printf("Enter student name , roll no. & total marks \n");

    for(i=0;i<n;i++){
        scanf("%s %d %d",&arr[i].name, &arr[i].roll, &arr[i].total_marks);
    }

    int ch;
    printf("Enter your choice\n");
    printf("1.Bubble Sort\n");
    printf("2.Quick Sort\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("No. of swaps are: %d \n",BubbleSort(arr,n));
        printf("Ascending sorted order is- \n");
        Display(arr, n);
        break;

    case 2:
        printf("No of swaps are: %d \n",count);
        printf("Ascending sorted order is- \n");
        QuickSort(arr, 0, n);
        Display(arr, n);
    
    default:
        break;
    }

    return 0;
}
