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
    int brr[c][r];
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            brr[i][j]=arr[j][i];
        }
    }
    printf("the transpose of original matrix stored in other matrix is:");
     for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            printf("%d ",brr[i][j]);
        }
        printf("\n");
     }
     return 0;
}