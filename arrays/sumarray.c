#include<stdio.h>

int main() {
    int arr[5];
    int sum=0;
    for(int i=0;i<5;i++){
    int a=i+1;
    printf("Enter element %d:",a);
    scanf("%d",& arr[i]);}
    for(int i=0;i<5;i++){
        sum=sum+arr[i];
        }
     printf("The sum of all elements of array is %d",sum);
    
    return 0;
}