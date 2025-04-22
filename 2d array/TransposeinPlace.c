#include<stdio.h>
// only appliciable to nxn matrix that is where  rows=columns;
int main() {
    int n;
    printf("Enter the number of rows and coulmns: ");
    scanf("%d", &n);

    int arr[n][n];
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    // Print the original matrix
    printf("The original matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    //Print transpose
    for (int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
        }
         printf("The Transpose matrix is:\n");
          for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          printf("%d ",arr[i][j]);
        }
        // only appliciable to nxn matrix that is where matrix rows=columns.
     printf("\n");
    }
}
