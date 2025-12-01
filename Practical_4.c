/*Write a menu driven program to perform the following operations on the QUEUE using an
array. 1. Insert 2. Delete 3. Search 4. Change 5. Display the contents 6. Exit*/ 

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert element
void insert() {
    int x;
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &x);

        if (front == -1) front = 0; // first element
        queue[++rear] = x;

        printf("Inserted %d\n", x);
    }
}

// Delete element
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

// Search element
void search() {
    int x, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &x);

    for (int i = front; i <= rear; i++) {
        if (queue[i] == x) {
            printf("Element %d found at position %d\n", x, i - front + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found!\n");
}

// Change element at given position
void change() {
    int pos, value;

    printf("Enter position to change (starting from 1): ");
    scanf("%d", &pos);

    if (front == -1 || front + pos - 1 > rear) {
        printf("Invalid Position!\n");
    } else {
        printf("Enter new value: ");
        scanf("%d", &value);

        queue[front + pos - 1] = value;
        printf("Value changed!\n");
    }
}

// Display contents
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contents:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n---- QUEUE MENU ----\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Change\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: search(); break;
            case 4: change(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
