#include<stdio.h>
int factorial(int a){
    if (a==1)return 1;
    int fact= a*factorial(a-1);
     return fact;
}

int main() {
    int n;
    printf("enter value:");
    scanf("%d",&n);
    int Factorial=factorial(n);
    printf("The factorial of %d is %d",n,Factorial);
    
    return 0;
}