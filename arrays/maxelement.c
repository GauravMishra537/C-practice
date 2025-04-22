#include<stdio.h>

int main() {
    int arr[6];
    for(int i=0;i<=5;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",& arr[i]);
    }
    int max=arr[0];
    for(int i=1;i<=5;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    printf("The maximum element of array is %d",max);
    return 0;
}