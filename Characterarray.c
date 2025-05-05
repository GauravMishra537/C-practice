#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the character array: ");
    scanf("%d", &n);

    char arr[n];
    printf("Enter elements of the character array:\n");

    for (int i = 0; i < n; i++) {
        printf("Enter %d element: ", i + 1);
        scanf(" %c", &arr[i]); /* Note the space before %c Space before %c: The space in " %c" tells scanf to 
        skip any leading whitespace (including newlines) before reading the next character.*/
    }

    printf("The character array: ");
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }

    return 0;
}
