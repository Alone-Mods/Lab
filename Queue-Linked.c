#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue function
void enqueue() {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue function
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty...Underflow\n");
        return -1;
    } else {
        struct Node *temp = front;
        int rv = front->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
        return rv;
    }
}

// Display function
void displayQ() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue content: ");
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int ch, data;
    do {
        printf("\nMenu\n----\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                displayQ();
                break;
            case 2:
                data = dequeue();
                if (data != -1)
                    printf("The dequeued data is: %d\n", data);
                displayQ();
                break;
            case 3:
                displayQ();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
    return 0;
}
