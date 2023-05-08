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

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Elements of list are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
    printf("%d inserted at beginning\n", data);
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end\n", data);
}

void insertAtPosition(struct Node** headRef, int data, int position) {
    if (position == 0) {
        insertAtBeginning(headRef, data);
    } else {
        struct Node* newNode = createNode(data);
        struct Node* temp = *headRef;
        int i;
        for (i = 0; i < position-1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            printf("%d inserted at position %d\n", data, position);
        }
    }
}

void deleteNode(struct Node** headRef, int data) {
    struct Node* temp = *headRef;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in list\n", data);
    } else {
        if (temp->prev == NULL) {
            *headRef = temp->next;
        } else {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("%d deleted from list\n", data);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtPosition(&head, 15, 1);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 25, 4);
    display(head);

    // Delete nodes
    deleteNode(&head, 5);
    deleteNode(&head, 15);
    deleteNode(&head, 30);
    deleteNode(&head, 50);
    display(head);

    return 0;
}

