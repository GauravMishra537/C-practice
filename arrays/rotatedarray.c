#include<stdio.h>
void reverse(int arr[],int a,int b){
    for(int i=a,j=b;i<j;i++,j--){
        int temp =arr[i];
        arr [i]=arr [j];
        arr [j]=temp;
    }
    return;
}

int main() {
    int n;
    printf("Enter size of array:");
    scanf("%d",& n);
    int k;
    printf("Enter no of rotations of array:");
    scanf("%d",& k);
    k=k%n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        printf("Enter element %d of array:",i+1);
        scanf("%d",& arr[i]);
    }
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    for (int i=0;i<=n-1;i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}