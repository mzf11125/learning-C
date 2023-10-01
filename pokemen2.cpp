#include <stdio.h>

int main() {
    double X, Y;

    scanf("%lf %lf", &X, &Y);

    if (X >= 1 && X <= 1000000 && Y >= 1 && Y <= 1000000 && Y >= X) {

        double division = X / Y;

        double result = division * 100;

        printf("%.2lf%%\n", result);
    }
    else {
        printf("Numbers must be between 1 and 1000000, and Y must be greater than or equal to X.\n");
    }

    return 0;
}
