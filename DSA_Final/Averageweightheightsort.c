#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    float height;
    float weight;
};

int z = 0;

// Bubble sort function to sort employees based on average of height and weight
void bubblesort(struct Employee arr[], int n) {
    int i, j;
    struct Employee temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            float avg1 = (arr[j].height + arr[j].weight) / 2;
            float avg2 = (arr[j+1].height + arr[j+1].weight) / 2;
            if (avg1 > avg2) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                z++;
            }
        }
    }
}

int main() {
    struct Employee employees[5] = {
        {"Alice", 5.5, 60.0},
        {"Bob", 6.0, 70.0},
        {"Charlie", 5.8, 65.0},
        {"Dave", 5.9, 75.0},
        {"Emily", 5.7, 68.0}
    };

    bubblesort(employees, 5);

    printf("List of employees sorted based on average of height and weight:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, height: %.2f, weight: %.2f\n", employees[i].name, employees[i].height, employees[i].weight);
    }

    printf("Number of swaps is: %d\n",z);

    return 0;
}
