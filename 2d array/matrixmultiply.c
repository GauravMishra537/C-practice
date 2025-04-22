#include<stdio.h>

int main() {
    int r1,r2,c1,c2;
    printf("Enter no of rows in matrix1:");
    scanf("%d",&r1);
    printf("Enter no of columns in matrix1:");
    scanf("%d",&c1);
    printf("Enter no of rows in matrix2:");
    scanf("%d",&r2);
    printf("Enter no of columns in matrix2:");
    scanf("%d",&c2);
    int matrix1[r1][c1];
    int matrix2[r2][c2];
    int i,j,k;
    if(r2!=c1){
        printf("Matrix multiplication is not possible");
    }
    else if(r2==c1){
        int result[r1][c2];
        printf("enter elements of matrix1:\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                printf("Enter element at %d row and %d column:",i+1,j+1);
                scanf("%d",& matrix1[i][j]);
            }
        }
         printf("enter elements of matrix2:\n");
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                printf("Enter element at %d row and %d column:",i+1,j+1);
                scanf("%d",& matrix2[i][j]);
            }
        }
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                result[i][j]=0;
                for(k=0;k<r2;k++){
                    result[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
        printf("Product of 2 matrix is:\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                printf("%d ",result[i][j]);
            }
            printf("\n");
        }
        
    }
    
    return 0;
}