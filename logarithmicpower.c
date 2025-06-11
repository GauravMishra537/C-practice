#include<stdio.h>
int power(int a,int b){
    if (b==0)return 1;
    if (b==1) return a;
    int x=power(a,b/2);
    if (b%2==0){
        return x*x;
    }
    else return x*x*a;

}

int main() {
    int a;
    printf("Enter base number:");
    scanf("%d",&a);
    int b;
    printf("Enter exponent:");
    scanf("%d",&b);
    int p=power(a,b);
    printf("%d raised to power %d is %d",a,b,p);
    
    return 0;
    
    return 0;
}