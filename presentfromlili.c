#include <stdio.h>

int main() {
    double L, B, H; 
    double result;

    scanf("%lf %lf %lf", &L, &B, &H);
    
    double side_area = B * H; 
    double base_area = 3 * L * B; 
    result = side_area + base_area;

    printf("%.3lf\n", result);

    return 0;
}

