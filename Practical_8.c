/*Write a program to implement Searching Algorithms
1. Sequential search
2. Binary search */

#include <stdio.h>

// Sequential Search
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // position found
    }
    return -1; // not found
}

// Binary Search (Array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // not found
}

int main() {
    int arr[50], n, key, choice, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements (sorted for binary search):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n--- SEARCHING MENU ---\n");
        printf("1. Sequential Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                pos = sequentialSearch(arr, n, key);
                if (pos == -1)
                    printf("Element not found!\n");
                else
                    printf("Element found at position %d\n", pos + 1);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                pos = binarySearch(arr, n, key);
                if (pos == -1)
                    printf("Element not found!\n");
                else
                    printf("Element found at position %d\n", pos + 1);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
