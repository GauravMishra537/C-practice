#include<stdio.h>

int main() {
    int arr[6];
    int add;
    int multiple;
    for(int i=0;i<6;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<=5;i++){
        if(i%2==0){
        add=arr[i]+10;
          printf("%d ",add);
       }
       
 else{
    multiple =2*(arr[i]);
        
     printf("%d ", multiple);
 }
    }return 0;
}