/*Write a program to implement following sorting algorithms
 Selection sort
 Bubble sort
 Merge sort
 Quick sort*/
#include <stdio.h>

// ---------------- SELECTION SORT ----------------
void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// ---------------- BUBBLE SORT ----------------
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ---------------- MERGE SORT ----------------
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------------- QUICK SORT ----------------
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1, temp;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }

    temp = arr[i + 1]; arr[i + 1] = arr[right]; arr[right] = temp;
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

// ---------------- DISPLAY ARRAY ----------------
void display(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------------- MAIN MENU ----------------
int main() {
    int arr[50], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nSorting Menu:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            break;
        case 3:
            mergeSort(arr, 0, n - 1);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!");
            return 0;
    }

    display(arr, n);

    return 0;
}

/*Enter number of elements: 5
Enter array elements:
10 3 5 2 7

Sorting Menu:
1. Selection Sort
2. Bubble Sort
3. Merge Sort
4. Quick Sort
Enter your choice: 2

Sorted array: 2 3 5 7 10
*/