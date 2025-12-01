/*Write a menu driven program to perform the following operations on a Singly Linked list.
1. Insert 6. Search
2. Insend 7. Sort
3. Insat 8. Count
4. Delete 9. Display
5. Reverse 10. Exit */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// 1. Insert at beginning
void insert() {
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;

    printf("Inserted at beginning!\n");
}

// 2. Insert at end
void insend() {
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Inserted at end!\n");
}

// 3. Insert at given position
void insat() {
    int pos, x;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        printf("Inserted at position %d!\n", pos);
        return;
    }

    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Inserted at position %d!\n", pos);
    }
}

// 4. Delete node
void deleteNode() {
    int x;
    printf("Enter value to delete: ");
    scanf("%d", &x);

    struct node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (prev == NULL)
        head = head->next;   // deleting first node
    else
        prev->next = temp->next;

    free(temp);
    printf("Node deleted!\n");
}

// 5. Reverse list
void reverse() {
    struct node *prev = NULL, *cur = head, *next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;

    printf("List reversed!\n");
}

// 6. Search node
void search() {
    int x, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &x);

    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("Value found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Value not found!\n");
}

// 7. Sort list
void sort() {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted!\n");
}

// 8. Count nodes
void count() {
    int c = 0;
    struct node *temp = head;

    while (temp != NULL) {
        c++;
        temp = temp->next;
    }

    printf("Total nodes = %d\n", c);
}

// 9. Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert (begin)\n2. Insend\n3. Insat\n4. Delete\n5. Reverse\n");
        printf("6. Search\n7. Sort\n8. Count\n9. Display\n10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: insend(); break;
            case 3: insat(); break;
            case 4: deleteNode(); break;
            case 5: reverse(); break;
            case 6: search(); break;
            case 7: sort(); break;
            case 8: count(); break;
            case 9: display(); break;
            case 10: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
