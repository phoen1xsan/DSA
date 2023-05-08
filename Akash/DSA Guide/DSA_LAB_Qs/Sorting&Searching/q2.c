#include <stdio.h>

struct stud
{
    char name[30];
    int roll, total_marks;
};

int InsertionSort(struct stud a[], int n){
    int i,j,c=0;
    struct stud x;
    for(i=1;i<n;i++){
        j=i-1;
        x=a[i];
        while(j!=-1 && a[j].roll>x.roll){
            a[j+1]=a[j];
            c++;
            j--;
        }
        a[j+1]=x;
        c++;
    }
    return c;
}

void Merge(struct stud a[], int l, int mid, int h){
    int i=l, j=mid + 1, k=l;
    struct stud b[100];
    while (i<=mid && j<=h)
    {
        if(a[i].roll<a[j].roll) b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    for(;i<=mid;i++){
        b[k++]=a[i];
    }
    for(;j<=h;j++){
        b[k++]=a[j];
    }
    for(i=l;i<=h;i++){
        a[i]=b[i];
    }
    
}

void IMergeSort(struct stud a[], int n){
    int i, p, l, mid, h;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(a,l,mid,h);
        }
    }
    if((p/2)<n) Merge(a,0,p/2-1,n-1);
}

void Display(struct stud a[], int n){
    int i = 0;
    for(i=0;i<n;i++){
        printf("%s %d %d \n",a[i].name,a[i].roll,a[i].total_marks);
    }
}

int main(){
    int n;
    printf("Enter no. of students: ");
    scanf("%d", &n);

    struct stud a[n];
    int i=0;
    printf("Enter student's name , roll no & total marks \n");
    for(i=0;i<n;i++){
        scanf("%s %d %d",&a[i].name,&a[i].roll,&a[i].total_marks);
    }

    int ch;
    printf("Enter your choice:\n");
    printf("1.Insertion Sort\n");
    printf("2.Merge Sort\n");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("No. of swaps performed are: %d \n",InsertionSort(a,n));
        printf("Ascending sorted order is- \n");
        Display(a,n);
        break;

    case 2:
        printf("Ascending sorted order is- \n");
        IMergeSort(a,n);
        Display(a,n);
    
    default:
        break;
    }

    return 0;
}