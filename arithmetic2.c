#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    if (A < 1 || A > 1000 || B < 1 || B > 1000) {
        printf("Error: A and B must be between 1 and 1000.\n");
        return 1;
    }
    int sum = A + B;
    int difference = A - B;
    int product = A * B;
    int quotient, remainder;
    if (B != 0) {
        quotient = A / B;
        remainder = A % B;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }
    printf("%d\n", sum);
    printf("%d\n", difference);
    printf("%d\n", product);
    printf("%d\n", quotient);
    printf("%d\n", remainder);
    return 0;
}
