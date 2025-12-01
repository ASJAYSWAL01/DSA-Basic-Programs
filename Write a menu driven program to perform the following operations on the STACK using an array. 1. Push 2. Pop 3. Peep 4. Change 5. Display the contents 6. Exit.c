#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Function to push an element
void push() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Pushed %d\n", x);
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped element = %d\n", stack[top]);
        top--;
    }
}

// Function to peep (view element at position from top)
void peep() {
    int pos;
    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (top - pos + 1 < 0) {
        printf("Invalid Position!\n");
    } else {
        printf("Element at position %d is %d\n", pos, stack[top - pos + 1]);
    }
}

// Change function → change element at given position
void change() {
    int pos, value;
    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (top - pos + 1 < 0) {
        printf("Invalid Position!\n");
    } else {
        printf("Enter new value: ");
        scanf("%d", &value);
        stack[top - pos + 1] = value;
        printf("Value changed!\n");
    }
}

// Display Function
void display() {
    if (top == -1) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n2. Pop\n3. Peep\n4. Change\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: change(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid Choice!\n");
        }
    }
}
