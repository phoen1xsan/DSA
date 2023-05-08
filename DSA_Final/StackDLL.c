#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* top = NULL;

void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    temp->prev = NULL;
    if (top != NULL) {
        top->prev = temp;
    }
    top = temp;
}

void Pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    free(temp);
}

void display() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Push(2);
    Push(4);
    Push(6);
    Push(8);
    display();
    Pop();
    Pop();
    display();
    return 0;
}
