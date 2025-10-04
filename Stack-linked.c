#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int poppedValue = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Display function
void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack content:\n");
        while (temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int ch, data, rv;
    do {
        printf("\nMenu\n----\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(data);
                displayStack();
                break;

            case 2:
                rv = pop();
                if (rv != -1)
                    printf("Popped Value is: %d\n", rv);
                displayStack();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}
