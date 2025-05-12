#include <stdio.h>

int binary_search(int arr[], int sno, int n);

int main() {
    int n, sno;
    
    // Input the number of elements
    printf("Enter how many numbers you want to enter: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("Enter the elements of array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the search number
    printf("Enter the search number: ");
    scanf("%d", &sno);

    // Perform binary search
    int result = binary_search(arr, sno, n);
    
    // Output the result
    if (result == -1) {
        printf("Not found\n");
    } else {
        printf("The position of the given search number is %d\n", result + 1);  // Position is 1-based
    }
    
    return 0;
}

int binary_search(int arr[], int sno, int n) {
    int left = 0, right = n - 1;
    
    while (left<= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index
        
        // Check if the search number is at the mid
        if (arr[mid] == sno) {
            return mid;  // Return the index of the search number
        }
        
        // If the search number is greater, ignore the left half
        if (arr[mid] < sno) {
            left= mid + 1;
        }
        // If the search number is smaller, ignore the right half
        else {
           right = mid - 1;
        }
    }
    
    return -1;  // If not found, return -1
}