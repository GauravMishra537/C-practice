#include <stdio.h>
#define Max 100

int sequential_search(int arr[], int sno, int n);

int main() {
    int n, sno;
    printf("Enter how many numbers you want to enter: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the search number: ");
    scanf("%d", &sno);

    int val = sequential_search(arr, sno, n);
    if (val == -1)
        printf("Not found\n");
    else
        printf("The position of the given search number is %d\n", val);
    
    return 0;
}

int sequential_search(int arr[], int sno, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == sno)
            return i + 1;  
    }
    return -1; 
}
