/*Write a program to solve the problem of Tower of Hanoi (Application of stack)*/ 

#include <stdio.h>

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Move (n-1) disks from source to auxiliary
    towerOfHanoi(n - 1, from, aux, to);

    // Move largest disk from source to destination
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Move (n-1) disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nTower of Hanoi Steps:\n");
    towerOfHanoi(n, 'A', 'C', 'B');  
    // A = Source, C = Destination, B = Auxiliary

    return 0;
}
