#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    double rotations[T];  

    for (int i = 0; i < T; i++) {
        double A, B;
        scanf("%lf %lf", &A, &B);

        rotations[i] = B * A / 360; 
    }

    for (int i = 0; i < T; i++) {
        printf("%.2lf\n", rotations[i]); 
    }

    return 0;
}
