#include<stdio.h>

int main() {
    int n, m,i;
    int sum = 0;
    int table = 0;

    // Get user input for n and m
    printf("Enter the first number (n): ");
    scanf("%d", &n);
    printf("Enter the second number (m): ");
    scanf("%d", &m);

    // Calculate sum of multiples of 'n' less than 'm'
    while (table <= m - n) {
        table = n * i;
        sum = sum + table;
        printf("%d ", table);
        i++;
    }
    printf("\nSum of multiples of %d less than %d: %d\n", n, m, sum);

    // Initialize sum1 to 0
    int sum1 = 0;  // Initialize sum1 to 0

    // Calculate sum of all numbers less than 'm' excluding multiples of 'n'
    for (i = 1; i < m; i++) {
        if (i % n != 0) {
            sum1 = sum1 + i;
        }
    }
    printf("Sum of all numbers less than %d excluding multiples of %d: %d\n", m, n, sum1);

    // Calculate and print the difference
    int c = sum - sum1;
    printf("Difference between the two sums: %d\n", c);

    return 0;
}
