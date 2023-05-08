#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Define a circular queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the circular queue
void addQ(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->rear->next = q->front;
    printf("%d added to queue\n", data);
}

// Function to delete an element from the circular queue
void deqQ(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else if (q->front == q->rear) {
        printf("%d deleted from queue\n", q->front->data);
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        printf("%d deleted from queue\n", temp->data);
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
}

// Function to display the elements of the circular queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = q->front;
        printf("Elements of queue are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != q->front);
        printf("\n");
    }
}

// Main function
int main() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    int n,m,x;

    printf("Enter the number of elements to enter in Q: \n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        addQ(q, x);
    }

    // Display the elements of the queue
    display(q);

    printf("Enter the number of elements to delete in Q: \n");
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        deqQ(q);
    }

    // Display the elements of the queue
    display(q);

    // Add elements to the queue
    addQ(q, 6);
    addQ(q, 7);

    // Display the elements of the queue
    display(q);

    return 0;
}
