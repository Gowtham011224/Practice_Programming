#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2; 


    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    printf("Building max heap for the first time:\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        printf("Heapified: ");
        printArray(arr, n);
    }

    printf("\nInitial stage:\n");
    printf("Unsorted: ");
    printArray(arr, n);
    
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);

        printf("\nIntermediate stage:\n");
        printf("Unsorted: ");
        printArray(arr, i);
        printf("Sorted:   ");
        printArray(arr + i, n - i);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("\nFinal sorted array: ");
    printArray(arr, n);

    free(arr);

    return 0;
}
