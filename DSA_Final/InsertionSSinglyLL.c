#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, struct Node* newNode) {
    struct Node* current;

    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;

        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertionSort(struct Node** head) {
    struct Node* sortedList = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* nextNode = current->next;
        insertNode(&sortedList, current);
        current = nextNode;
    }

    *head = sortedList;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("Elements of list are: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n,x;

    printf("Enter the number of elements to enter in LL: \n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        insertNode(&head, createNode(x));
    }

    printf("Unsorted list:\n");
    display(head);

    insertionSort(&head);

    printf("Sorted list:\n");
    display(head);

    return 0;
}
