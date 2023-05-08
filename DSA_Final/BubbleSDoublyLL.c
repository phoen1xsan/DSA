#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addFront(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
}

void swapData(struct Node* node1, struct Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void bubbleSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node* i, *j;
    int swapped;
    for (i = head; i->next != NULL; i = i->next) {
        swapped = 0;
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                swapData(j, j->next);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        printf("Elements of list are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n,x;
    printf("Enter number of elements to be added: \n");
    scanf("%d", &n);
    printf("Enter the elements: \n");

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        addFront(&head, x);
    }

    printf("Before sorting:\n");
    display(head);

    bubbleSort(head);

    printf("After sorting:\n");
    display(head);

    return 0;
}
