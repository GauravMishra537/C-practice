#include<stdio.h>

int main() {
    int n;
    int arr[5];
    int product=1;
    for(int i=0;i<=4;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<=4;i++){
        product=product*arr[i];
    }
    printf("The product of elements of array is %d",product);
    return 0;
}