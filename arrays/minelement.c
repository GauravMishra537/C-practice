#include<stdio.h>

int main() {
    int arr[6];
    for(int i=0;i<=5;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",& arr[i]);
    }
    int min=arr[0];
    for(int i=1;i<=5;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    printf("The minimum element of array is %d",min);
    return 0;
}