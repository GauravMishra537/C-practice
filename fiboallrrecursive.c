#include <stdio.h>
int fibonacci(int n) {
    if (n==1) return 0;
    if (n==2) return 1;
    int answer= fibonacci(n - 1) + fibonacci(n - 2);
    return answer;
}

int main() {
    int n;
    printf("Enter number of term:");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
