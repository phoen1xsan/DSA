#include <stdio.h>

struct emp{
    char name[40];
    int no, sal;
}

void ShellSort()

void main(){
    int n,i;
    prinf("Enter no. of employees: ");
    scanf("%d,"&n);
    struct emp a[n];
    printf("Enter name , no. and salary of the employees-\n");
    for(i=0;i<n;i++){
        scanf("%s %d %d",&a[i].name, &a[i].no,&a[i].sal);
    }

}