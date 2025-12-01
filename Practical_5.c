/*Write a menu driven program to perform the following operations on the CIRCULARQUEUE
using an array. 1. Insert 2. Delete 3. Search 4. Change 5. Display the contents 6. Exit*/

#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

// Insert element
void insert() {
    int x;

    // If queue is full
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &x);

    if (front == -1) {         // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    cq[rear] = x;
    printf("Inserted %d\n", x);
}

// Delete element
void delete() {
    if (front == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("Deleted %d\n", cq[front]);

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Search for element
void search() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    int x, pos = 1, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &x);

    int i = front;
    while (1) {
        if (cq[i] == x) {
            printf("Element %d found at position %d\n", x, pos);
            found = 1;
            break;
        }

        if (i == rear) break;   // reached end of queue

        i = (i + 1) % MAX;
        pos++;
    }

    if (!found)
        printf("Element not found!\n");
}

// Change element at given position
void change() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    int pos, value, count = 1;
    printf("Enter position to change (starting from 1): ");
    scanf("%d", &pos);

    int i = front;
    while (count < pos && i != rear) {
        i = (i + 1) % MAX;
        count++;
    }

    if (count == pos) {
        printf("Enter new value: ");
        scanf("%d", &value);
        cq[i] = value;
        printf("Value changed!\n");
    } else {
        printf("Invalid position!\n");
    }
}

// Display queue
void display() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Circular Queue contents: ");
    int i = front;

    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n---- CIRCULAR QUEUE MENU ----\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Change\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
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
