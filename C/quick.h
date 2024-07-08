#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int p = arr[high];
    int l = low;
    int r = high - 1;

    while (1) {
        while (l <= r && arr[l] <= p) {
            l++;
        }

        while (l <= r && arr[r] >= p) {
            r--;
        }

        if (l < r) {
            swap(&arr[l], &arr[r]);
             
            l++;
            r--;
        } else {
            break;
        }
    }

    swap(&arr[l], &arr[high]);
   
    return l;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void quickSort()
{
    printf("Enter the size of the array\n");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Size of array is invalid!!");
        return ;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("enter number:");
        scanf("%d", &arr[i]);
    }

    printf("Given array is \n");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return;
}
