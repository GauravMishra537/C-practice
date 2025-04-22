#include<stdio.h>

int main() {
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int arr[r][c];
    
    // Input array elements
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element at row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    // Print the original matrix
    printf("The original matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int max = arr[0][0];
    int min = arr[0][0];
    int maxRow = 0, maxCol = 0; // Indices of max element
    int minRow = 0, minCol = 0; // Indices of min element

    // Find max and min elements with their indices
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxRow = i;
                maxCol = j;
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    // Print results
    printf("The maximum element of the matrix is %d at position (%d, %d)\n", max, maxRow + 1, maxCol + 1);
    printf("The minimum element of the matrix is %d at position (%d, %d)\n", min, minRow + 1, minCol + 1);

    return 0;
}
