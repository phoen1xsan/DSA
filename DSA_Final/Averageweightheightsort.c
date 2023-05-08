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
    int m;
    printf("Enter number of employees: \n");
    scanf("%d", &m);
    struct Employee employees[m];

    printf("Enter details of employees:\n");
    for (int i = 0; i < m; i++) {
        printf("Employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Height: ");
        scanf("%f", &employees[i].height);
        printf("Weight: ");
        scanf("%f", &employees[i].weight);
    }

    bubblesort(employees, m);

    printf("\nList of employees sorted based on average of height and weight:\n");
    for (int i = 0; i < m; i++) {
        printf("%s, height: %.2f, weight: %.2f\n", employees[i].name, employees[i].height, employees[i].weight);
    }

    printf("Number of swaps is: %d\n",z);
    return 0;
}
