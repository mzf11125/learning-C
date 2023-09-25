#include <stdio.h>

int main() {
    int X;
    double Y;

    
    scanf("%d %lf", &X, &Y);

   
    if (X < 1 || X > 100000 || Y < 0.00 || Y > 1000.00) {
        printf("Error: X must be between 1 and 100000, and Y must be between 0.00 and 1000.00.\n");
        return 1;  
    }


    double futureValue = X;
    for (int i = 0; i < 3; i++) {
        futureValue = futureValue + (futureValue * (Y / 100.0));
    }


    printf("%.2lf\n", futureValue);

    return 0;
}
