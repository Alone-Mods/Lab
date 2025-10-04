#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at Beginning
void InsertionBeginning() {
    int item;
    struct node *new;
    printf("Enter the data to be added: ");
    scanf("%d", &item);

    new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->next = head;
    head = new;

    printf("Inserted %d at the beginning.\n", item);
}

// Insert at End
void InsertionEnd() {
    int item;
    struct node *new, *temp;
    printf("Enter the data to be added: ");
    scanf("%d", &item);

    new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->next = NULL;

    if (head == NULL) {
        head = new;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }

    printf("Inserted %d at the end.\n", item);
}

// Insert After a value
void InsertionAfter() {
    int item, x;
    struct node *new, *temp;
    printf("Enter the data to be added: ");
    scanf("%d", &item);
    printf("After Which Element? :");
    scanf("%d", &x);

    new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->next = NULL;

    if (head == NULL) {
        printf("List is empty, inserting %d as the first node.\n", item);
        head = new;
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found, insertion failed.\n", x);
        free(new);
    } else {
        new->next = temp->next;
        temp->next = new;
        printf("Inserted %d after %d.\n", item, x);
    }
}

// Delete from Beginning
void deleteBeginning() {
    struct node *temp;
    if (head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Delete from End
void deleteEnd() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted %d from the end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// Delete a given value
void deleteX() {
    struct node *temp, *prev;
    int item;
    printf("Enter the element to be deleted: ");
    scanf("%d", &item);

    if (head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    // If element is the first node
    if (head->data == item) {
        temp = head;
        head = head->next;
        printf("Deleted %d.\n", item);
        free(temp);
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", item);
    } else {
        prev->next = temp->next;
        printf("Deleted %d.\n", item);
        free(temp);
    }
}

// Display the list
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }

    printf("Linked List elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main
int main() {
    while (1) {
        int n;
        printf("\n--- MENU ---\n");
        printf("1. Insertion In Beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion After a value\n");
        printf("4. Delete from Beginning\n");
        printf("5. Deletion from End\n");
        printf("6. Delete a given value\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1: InsertionBeginning(); break;
            case 2: InsertionEnd(); break;
            case 3: InsertionAfter(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deleteX(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); exit(0);
            default: printf("Enter a valid choice.\n");
        }
    }
    return 0;
}
