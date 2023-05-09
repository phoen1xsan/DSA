#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll_no;
    char name[50];
    float marks;
};

// Function to perform binary search recursively
int binarySearchRecursive(struct student arr[], int low, int high, int roll_no) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // If the roll number is found at mid, return mid
        if (arr[mid].roll_no == roll_no) {
            return mid;
        }

        // If the roll number is greater than mid, search the right half of the array
        if (arr[mid].roll_no < roll_no) {
            return binarySearchRecursive(arr, mid + 1, high, roll_no);
        }

        // If the roll number is smaller than mid, search the left half of the array
        return binarySearchRecursive(arr, low, mid - 1, roll_no);
    }

    // If the roll number is not found, return -1
    return -1;
}

// Function to perform binary search iteratively
int binarySearchIterative(struct student arr[], int n, int roll_no) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the roll number is found at mid, return mid
        if (arr[mid].roll_no == roll_no) {
            return mid;
        }

        // If the roll number is greater than mid, search the right half of the array
        if (arr[mid].roll_no < roll_no) {
            low = mid + 1;
        }

        // If the roll number is smaller than mid, search the left half of the array
        else {
            high = mid - 1;
        }
    }

    // If the roll number is not found, return -1
    return -1;
}

int main() {
    int n, roll_no;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student arr[n];

    // Accepting student details
    for (int i = 0; i < n; i++) {
        printf("Enter the roll number, name, and marks of student %d: ", i+1);
        scanf("%d%s%f", &arr[i].roll_no, arr[i].name, &arr[i].marks);
    }

//    // Sorting the array in ascending order of roll numbers
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (arr[i].roll_no > arr[j].roll_no) {
//                struct student temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }

    // Accepting the roll number to be searched
    printf("Enter the roll number to be searched: ");
    scanf("%d", &roll_no);

    // Performing binary search recursively
    int result_recursive = binarySearchRecursive(arr, 0, n - 1, roll_no);
    if (result_recursive == -1) {
        printf("Roll number not found (recursive)\n");
    } else {
        printf("Roll number found at index %d (recursive)\n", result_recursive);
        printf("Details of the student:\n");
        printf("Roll number: %d\n", arr[result_recursive].roll_no);
        printf("Name: %s\n", arr[result_recursive].name);
        printf("Marks: %.2f\n", arr[result_recursive].marks);
    }

    // Performing binary search iteratively
    int result_iterative = binarySearchIterative(arr, n, roll_no);
    if (result_iterative == -1) {
        printf("Roll number not found (iterative)\n");
    } else {
        printf("Roll number found at index %d (iterative)\n", result_iterative);
        printf("Details of the student:\n");
        printf("Roll number: %d\n", arr[result_iterative].roll_no);
        printf("Name: %s\n", arr[result_iterative].name);
        printf("Marks: %.2f\n", arr[result_iterative].marks);
    }

    return 0;
}
