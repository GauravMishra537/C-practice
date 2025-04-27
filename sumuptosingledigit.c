#include <stdio.h>

int main() {
    int number, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 9) {
        int num1 = number % 100; 
        number /= 100;            
        sum += num1;
    }
    if (number > 0) {
        sum += number;
    }
    while (sum >= 10) {
        int temp_sum = 0;
        while (sum > 0) {
            temp_sum += sum % 10;
            sum /= 10;
        }
        sum = temp_sum; 
    }
     printf("Final result: %d\n", sum);
    
    return 0;
}
