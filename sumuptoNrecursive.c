#include<stdio.h>
int sum(int n){
    if(n==1)return 1;
    else return n+sum(n-1);
}

int main() {
    int n;
    printf("enter n:");
    scanf("%d",&n);
  int s= sum(n);
    printf("%d",s);
    return 0;
}