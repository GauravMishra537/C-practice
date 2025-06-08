#include <stdio.h>

// Corrected selection sort function
void selectionsort(int arr[], int n) {
    int i, j, minidx, temp;
    for (i = 0; i < n - 1; i++) {
        minidx = i; // assume the minimum is at position i
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minidx]) {
                minidx = j;
            }
        }
        // Swap only if a smaller element is found
        if (minidx != i) {
            temp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = temp;
        }
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter how many numbers you want to enter: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the selection sort function
    selectionsort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
