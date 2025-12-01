/*Write a menu driven program to perform the following operations on a Doubly Linked
list.1. Insert 2. Insend 3. Insat 4. Delete 5. Display 6. Exit*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Function to create a new node
struct node* createNode(int val) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// 1. Insert at beginning
void insert() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *newnode = createNode(val);

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

// 2. Insert at end (Insend)
void insend() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *newnode = createNode(val);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// 3. Insert at given position (Insat)
void insat() {
    int val, pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);

    if (pos == 1) {
        insert();
        return;
    }

    struct node *newnode = createNode(val);
    struct node *temp = head;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// 4. Delete node by value
void deleteNode() {
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    struct node *temp = head;

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted successfully.\n");
}

// 5. Display list
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- DOUBLY LINKED LIST MENU -----\n");
        printf("1. Insert (Beginning)\n");
        printf("2. Insend (End)\n");
        printf("3. Insat (Position)\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: insend(); break;
            case 3: insat(); break;
            case 4: deleteNode(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
