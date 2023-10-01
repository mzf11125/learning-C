#include <stdio.h>

int main() {
    double N[100], P[10000], undiscounted_price;

    for (int i = 0; i < 4; i++) {
        scanf("%lf %lf", &N[i], &P[i]);
    }

    for (int i = 0; i < 4; i++) {
        undiscounted_price = P[i] / ((100.0 - N[i]) / 100.0);
        printf("$%.2lf\n", undiscounted_price);
    }

    return 0;
}
