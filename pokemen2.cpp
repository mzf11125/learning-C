#include <stdio.h>

int main() {
    long long X, Y;

    printf("Enter two numbers (X and Y): ");
    scanf("%lld %lld", &X, &Y);

    if (X >= 1 && X <= 1000000 && Y >= 1 && Y <= 1000000 && Y >= X) {

        double division = (double)X / Y;

        long long result = division * 100;

        printf("%.2Lf\n", result);
    }
    else {
        printf("Numbers must be between 1 and 1000000, and Y must be greater than or equal to X.\n");
    }

    return 0;
}
