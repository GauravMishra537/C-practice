/*A matrix contain elements .Find the row which have maximum sum*/
#include<stdio.h>

int main() {
    int r,c;
    printf("Enter no of rows:");
    scanf("%d",&r);
    printf("enter no of columns:");
    scanf("%d",&c);
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter elements at %d rows and coulmns %d:",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }
    printf("The original matrix is:\n");
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
     }
     int Maxsum=0;
     int Maxidx=0;
     for(int i=0;i<r;i++){
        int sum=0;
        for(int j=0;j<c;j++){
            sum+=arr[i][j];
        }
        if(Maxsum<sum){
            Maxsum=sum;
            Maxidx=i;
        }
        printf("\n");
     }
     printf("the %d row has maximum sum of elements that is %d",Maxidx+1,Maxsum);

    return 0;
}
