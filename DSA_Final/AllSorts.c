// // Bubble sort
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// struct student{
//     int rollno;
//     int marks;
//     char name[100];
// };

// void swap(struct student *f, int first, int last, int *swaps){
//     int temp;
//     char tempchar[100];
//     temp = f[first].marks;
//     f[first].marks = f[last].marks;
//     f[last].marks = temp;
//     temp = f[first].rollno;
//     f[first].rollno = f[last].rollno;
//     f[last].rollno = temp;
//     strcpy(tempchar,f[first].name);
//     strcpy(f[first].name,f[last].name);
//     strcpy(f[last].name,tempchar);
//     (*swaps)++;
// }

// void bubble(struct student *array, int size, int *swaps){
//     for(int i=0; i<size-1; ++i){
//         for(int j=0; j<size-i-1; ++j){
//             if (array[j].rollno>array[j+1].rollno){
//                 swap(array,j,j+1,swaps);
//             }
//         }
//     }
// }

// int main(){
//     int j,count,swaps=0;
//     printf("Enter the number of students: \n");
//     scanf("%d", &count);
//     struct student array[count];

//     for(j=0; j<count; j++){
//         printf("Enter %d students roll no: \n",j);
//         scanf("%d", &array[j].rollno);
//         printf("Enter %d students marks: \n",j);
//         scanf("%d", &array[j].marks);
//         printf("Enter %d students name: \n",j);
//         scanf("%s", &array[j].name);
//     }

//     bubble(array,count,&swaps);
//     printf("Sorted order of students is: \n");
//     for(j=0; j<count; j++){
//         printf("student name: %s \n", array[j].name);
//         printf("student marks: %d \n", array[j].marks);
//         printf("student rollno: %d \n", array[j].rollno);
//     }
//     printf("No. of swaps performed are: %d \n", swaps);
// }




// // Merge sort
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// struct student{
//     int rollno;
//     int marks;
//     char name[100];
// };

// void assign(struct student *f, int first, struct student *g, int last){
//     f[first].rollno = g[last].rollno;
//     f[first].marks = g[last].marks;
//     strcpy(f[first].name,g[last].name);
// }

// void merge(struct student *array, int start, int mid, int end){
//     int len1 = mid-start+1;
//     int len2 = end-mid;

//     struct student leftArray[len1], rightArray[len2];

//     for(int i=0; i<len1; i++){
//         assign(leftArray,i,array,start+i);
//     }

//     for(int j=0; j<len2; j++){
//         assign(rightArray,j,array,mid+1+j);
//     }

//     int i, j, k;
//     i = 0, j = 0, k = start;
//     while(i<len1 && j<len2){
//         if(leftArray[i].rollno < rightArray[j].rollno){
//             assign(array,k,leftArray,i);
//             i++;
//         }
//         else{
//             assign(array,k,rightArray,j);
//             j++;
//         }
//         k++;
//     }
    
//     while(i<len1){
//         assign(array,k,leftArray,i);
//         i++;
//         k++;
//     }

//     while(j<len2){
//         assign(array,k,rightArray,j);
//         j++;
//         k++;
//     }
// }

// void mergeSort(struct student *array, int start, int end){
//     if(start<end){
//         int mid = start + (end-start)/2;
//         mergeSort(array,start,mid);
//         mergeSort(array,mid+1,end);
//         merge(array,start,mid,end);
//     }
// }

// int main(){
//     int i, count=0;
//     printf("Enter number of students: \n");
//     scanf("%d", &count);
//     struct student array[count];
//     for(i=0; i<count; i++){
//         printf("Enter Student rollno: \n");
//         scanf("%d",&array[i].rollno);
//         printf("Enter Student marks: \n");
//         scanf("%d",&array[i].marks);
//         printf("Enter Student name: \n");
//         scanf("%s",&array[i].name);
//     }

//     mergeSort(array, 0, count-1);
//     printf("Sorted order of students is: \n");
//     for(i=0; i<count; i++){
//         printf("student rollno: %d \n", array[i].rollno);
//         printf("student marks: %d \n", array[i].marks);
//         printf("student name: %s \n", array[i].name);
//     }
// }




// //Heap Sort
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct student{
//     int rollno;
//     int marks;
//     char name[100];
// };

// int z=0;

// void swap(struct student *f, int first, int last){
//     int temp;
//     char tempchar[100];
//     temp = f[first].marks;
//     f[first].marks = f[last].marks;
//     f[last].marks = temp;
//     temp = f[first].rollno;
//     f[first].rollno = f[last].rollno;
//     f[last].rollno = temp;
//     strcpy(tempchar, f[first].name);
//     strcpy(f[first].name, f[last].name);
//     strcpy(f[last].name, tempchar);
//     z++;
// }

// void heapify(struct student *array, int n, int i){
//     int max = i;
//     int leftChild = 2*i+1;
//     int rightChild = 2*i+2;
//     if(leftChild<n && array[leftChild].rollno < array[max].rollno)
//         max = leftChild;
//     if(rightChild<n && array[rightChild].rollno < array[max].rollno)
//         max = rightChild;
//     if(max != i){
//         swap(array,i,max);
//         heapify(array,n,max); 
//     }
// }

// void heapSort(struct student *array, int n){
//     for(int i=n/2-1; i>=0; i--)
//         heapify(array,n,i);
//     for(int i=n-1; i>=0; i--){
//         swap(array,0,i);
//         heapify(array,i,0);
//     }
// }

// int main(){
//     int i, n;
//     printf("Enter total number of students: \n");
//     scanf("%d", &n);
//     struct student array[n];

//     for(i=0; i<n; i++){
//         printf("Enter student rollno: \n");
//         scanf("%d", &array[i].rollno);
//         printf("Enter student marks: \n");
//         scanf("%d", &array[i].marks);
//         printf("Enter student name: \n");
//         scanf("%s", &array[i].name);
//     }

//     heapSort(array,n);
//     printf("Sorted order of students is: \n");
//     for(i=0; i<n; i++){
//         printf("student rollno: %d \n", array[i].rollno);
//         printf("student marks: %d \n", array[i].marks);
//         printf("student name: %s \n", array[i].name);
//     }

//     printf("Number of swaps is: %d\n",z);
// }




// //Quick Sort
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct student{
//     int rollno;
//     int marks;
//     char name[100];
// };

// int n = 0;

// void swap(struct student *f, int first, int last){
//     int temp;
//     char tempchar[100];
//     temp = f[first].rollno;
//     f[first].rollno = f[last].rollno;
//     f[last].rollno = temp;
//     temp = f[first].marks;
//     f[first].marks = f[last].marks;
//     f[last].marks = temp;
//     strcpy(tempchar, f[first].name);
//     strcpy(f[first].name, f[last].name);
//     strcpy(f[last].name, tempchar);
// }

// void quickSort(struct student *f, int first, int last){
//     int i,j,temp,pivot;
//     if(first<last){
//         pivot = f[first].rollno;
//         i = first;
//         j = last;

//         while(i<j){
//             while(f[i].rollno<=pivot && i<last){
//                 i++;
//             }
//             while(f[j].rollno>pivot){
//                 j--;
//             }
//             if(i<j){
//                 swap(f,i,j);
//                 n++;
//             }
//         }

//         swap(f,j,first);
//         n++;
//         quickSort(f,first,j-1);
//         quickSort(f,j+1,last);
//     }
// }

// int main(){
//     int i,count;
//     printf("Enter the number of students: \n");
//     scanf("%d", &count);
//     struct student array[count];

//     for(i=0; i<count; i++){
//         printf("Enter student rollno: \n");
//         scanf("%d", &array[i].rollno);
//         printf("Enter student marks: \n");
//         scanf("%d", &array[i].marks);
//         printf("Enter student name: \n");
//         scanf("%s", &array[i].name);
//     }

//     quickSort(array,0,count-1);
//     printf("Sorted order of students is: \n");
//     for(i=0; i<count; i++){
//         printf("Student rollno: %d\n", array[i].rollno);
//         printf("Student marks: %d\n", array[i].marks);
//         printf("Student name: %s\n", array[i].name);
//     }

//     printf("Number of swaps performed are: %d\n", n);
//     return 0;
// }




// // Insertion Sort
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct student{
//     int rollno;
//     int marks;
//     char name[100];
// };

// int n = 0;

// void insertionSort(struct student *f, int m){
//     int i,j;
//     struct student key;
//     for(i=0; i<m; i++){
//         key = f[i];
//         j = i-1;
//         while(j>=0 && f[j].rollno>key.rollno){
//             f[j+1] = f[j];
//             j = j-1;
//             n++;
//         }
//         f[j+1] = key;
//     }
// }

// int main(){
//     int i, count;
//     printf("Enter number of students: \n");
//     scanf("%d", &count);
//     struct student array[count];

//     for(i=0; i<count; i++){
//         printf("Enter student rollno: \n");
//         scanf("%d", &array[i].rollno);
//         printf("Enter student marks: \n");
//         scanf("%d", &array[i].marks);
//         printf("Enter student name: \n");
//         scanf("%s", &array[i].name);
//     }

//     insertionSort(array,count);
//     printf("Sorted order of students is: \n");
//     for(i=0; i<count; i++){
//         printf("Student rollno: %d\n",array[i].rollno);
//         printf("Student marks: %d\n",array[i].marks);
//         printf("Student name: %s\n",array[i].name);
//     }

//     printf("The number of swaps performed are: %d\n", n);
//     return 0;
// }




// Selection Sort
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int rollno;
    int marks;
    char name[100];
};

int n = 0;

void swap(struct student *f, int a, int b){
    int temp;
    char tempchar[100];
    temp = f[a].rollno;
    f[a].rollno = f[b].rollno;
    f[b].rollno = temp;
    temp = f[a].marks;
    f[a].marks = f[b].marks;
    f[a].marks = temp;
    strcpy(tempchar, f[a].name);
    strcpy(f[a].name, f[b].name);
    strcpy(f[b].name, tempchar);
}

void selectionSort(struct student *f, int m){
    int i,j,min;
    for(i=0; i<m-1; i++){
        min = i;
        for(j=i+1; j<m; j++){
            if(f[j].rollno < f[min].rollno){
                min = j;
            }
        }

        if(min != i){
            swap(f, i, min);
            n++;
        }
    }
}

int main(){
    int i, count;
    printf("Enter number of students: \n");
    scanf("%d", &count);
    struct student array[count];

    for(i=0; i<count; i++){
        printf("Enter student rollno: \n");
        scanf("%d", &array[i].rollno);
        printf("Enter student marks: \n");
        scanf("%d", &array[i].marks);
        printf("Enter student name: \n");
        scanf("%s", &array[i].name);
    }

    selectionSort(array,count);
    printf("Sorted order of students is: \n");
    for(i=0; i<count; i++){
        printf("Student rollno: %d\n",array[i].rollno);
        printf("Student marks: %d\n",array[i].marks);
        printf("Student name: %s\n",array[i].name);
    }

    printf("Number of swaps performed: %d\n", n);
    return 0;
}
