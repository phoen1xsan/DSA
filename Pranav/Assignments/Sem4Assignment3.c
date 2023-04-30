#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} node;

// Function to insert a new term into a polynomial
node* insertNode(node* head, int coeff, int exp) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    } else {
        node* curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return head;
}

// Function to print a polynomial
void printPolynomial(node* head) {
    if(head == NULL) {
        printf("0\n");
    } else {
        while(head != NULL) {
            printf("%dx^%d ", head->coeff, head->exp);
            head = head->next;
            if(head != NULL) {
                printf("+ ");
            }
        }
        printf("\n");
    }
}

// Function to add two polynomials
node* addPolynomial(node* poly1, node* poly2) {
    node* result = NULL;
    node* curr1 = poly1;
    node* curr2 = poly2;
    while(curr1 != NULL && curr2 != NULL) {
        if(curr1->exp == curr2->exp) {
            int coef = curr1->coeff + curr2->coeff;
            result = insertNode(result, coef, curr1->exp);
            curr1 = curr1->next;
            curr2 = curr2->next;
        } else if(curr1->exp > curr2->exp) {
            result = insertNode(result, curr1->coeff, curr1->exp);
            curr1 = curr1->next;
        } else {
            result = insertNode(result, curr2->coeff, curr2->exp);
            curr2 = curr2->next;
        }
    }
    while(curr1 != NULL) {
        result = insertNode(result, curr1->coeff, curr1->exp);
        curr1 = curr1->next;
    }
    while(curr2 != NULL) {
        result = insertNode(result, curr2->coeff, curr2->exp);
        curr2 = curr2->next;
    }
    return result;
}

// Function to subtract two polynomials
node* subtractPolynomial(node* poly1, node* poly2) {
    node* result = NULL;
    node* curr1 = poly1;
    node* curr2 = poly2;
    while(curr1 != NULL && curr2 != NULL) {
        if(curr1->exp == curr2->exp) {
            int coef = curr1->coeff - curr2->coeff;
            result = insertNode(result, coef, curr1->exp);
            curr1 = curr1->next;
            curr2 = curr2->next;
        } else if(curr1->exp > curr2->exp) {
            result = insertNode(result, curr1->coeff, curr1->exp);
            curr1 = curr1->next;
        } else {
            result = insertNode(result, -curr2->coeff, curr2->exp);
            curr2 = curr2->next;
        }
    }
    while(curr1 != NULL) {
        result = insertNode(result, curr1->coeff, curr1->exp);
        curr1 = curr1->next;
    }
    while(curr2 != NULL) {
        result = insertNode(result, -curr2->coeff, curr2->exp);
        curr2 = curr2->next;
    }
    return result;
}

// Function to multiply two polynomials
node* multiplyPolynomial(node* poly1, node* poly2) {
    node* result = NULL;
    node* curr1 = poly1;
    while(curr1 != NULL) {
        node* curr2 = poly2;
        while(curr2 != NULL) {
            int coef = curr1->coeff * curr2->coeff;
            int exp = curr1->exp + curr2->exp;
            result = insertNode(result, coef, exp);
            curr2 = curr2->next;
        }
    curr1 = curr1->next;
    }
    return result;
}

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;
        // Taking user input for first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    int n1;
    scanf("%d", &n1);
    for(int i=0; i<n1; i++) {
        printf("Enter coefficient and exponent of term %d: ", i+1);
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        poly1 = insertNode(poly1, coeff, exp);
    }

    // Taking user input for second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    int n2;
    scanf("%d", &n2);
    for(int i=0; i<n2; i++) {
        printf("Enter coefficient and exponent of term %d: ", i+1);
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        poly2 = insertNode(poly2, coeff, exp);
    }

    // Printing both polynomials
    printf("First polynomial: ");
    printPolynomial(poly1);
    printf("Second polynomial: ");
    printPolynomial(poly2);

    // Adding the two polynomials and printing the result
    printf("Sum of the two polynomials: ");
    node* sum = addPolynomial(poly1, poly2);
    printPolynomial(sum);

    // Subtracting the two polynomials and printing the result
    printf("Difference of the two polynomials: ");
    node* diff = subtractPolynomial(poly1, poly2);
    printPolynomial(diff);

    // Multiplying the two polynomials and printing the result
    printf("Product of the two polynomials: ");
    node* product = multiplyPolynomial(poly1, poly2);
    printPolynomial(product);

    return 0;
}
