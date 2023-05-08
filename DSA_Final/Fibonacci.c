#include<stdio.h>

// Employee structure
struct Employee {
    char name[50];
    int id;
    float salary;
};

// Function to perform Fibonacci search without recursion
int fibonacciSearch(struct Employee arr[], int n, int id) {
    int fib2 = 0;  // (m-2)'th Fibonacci Number
    int fib1 = 1;  // (m-1)'th Fibonacci Number
    int fib = fib2 + fib1;  // m'th Fibonacci Number

    // Find the smallest Fibonacci number that is greater than or equal to n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;  // Index of the smallest element in the array greater than or equal to id

    // Perform the search
    while (fib > 1) {
        int i = (offset + fib2 < n) ? offset + fib2 : n - 1;

        if (arr[i].id < id) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i].id > id) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    // If the element is not found, return -1
    if (fib1 && arr[offset + 1].id == id) {
        return offset + 1;
    }

    return -1;
}

// Function to perform Fibonacci search with recursion
int fibonacciSearchRecursive(struct Employee arr[], int n, int id, int fib1, int fib2, int offset) {
    if (fib1 && arr[offset + 1].id == id) {
        return offset + 1;
    }

    if (fib1 == 0 || offset == n - 1) {
        return -1;
    }

    int fib = fib2 + fib1;
    int i = (offset + fib2 < n) ? offset + fib2 : n - 1;

    if (arr[i].id < id) {
        return fibonacciSearchRecursive(arr, n, id, fib1 - fib2, fib2, i);
    } else if (arr[i].id > id) {
        return fibonacciSearchRecursive(arr, n, id, fib1, fib2 - fib1, offset);
    } else {
        return i;
    }
}

// Main function
int main() {
    // Initialize employee records
    struct Employee employees[10] = {
        {"Alice", 1001, 50000},
        {"Bob", 1002, 60000},
        {"Charlie", 1003, 70000},
        {"Dave", 1004, 80000},
        {"Emily", 1005, 90000},
        {"Frank", 1006, 100000},
        {"Gina", 1007, 110000},
        {"Harry", 1008, 120000},
        {"Ivan", 1009, 130000},
        {"Julia", 1010, 140000}
    };

    // Perform Fibonacci search without recursion
    int index1 = fibonacciSearch(employees, 10, 1004);

    if (index1 == -1) {
        printf("Employee record not found\n");
    } else {
        printf("Employee record found at index %d:\n", index1);
        printf("Name: %s\n", employees[index1].name);
        printf("ID: %d\n", employees[index1].id);
        printf("Salary: %.2f\n", employees[index1].salary);
    }

    // Perform Fibonacci search with recursion
    int index2 = fibonacciSearchRecursive(employees, 10, 1007, 8, 5, -1);

    if (index2 == -1) {
        printf("Employee record not found\n");
    } else {
        printf("Employee record found at index %d:\n", index2);
        printf("Name: %s\n", employees[index2].name);
        printf("ID: %d\n", employees[index2].id);
        printf("Salary: %.2f\n", employees[index2].salary);
    }

    return 0;
}

