#include <stdio.h>
#include <string.h>

int main() {
    char N1[101], N2[101];  
    double H1, H2;      
    int A1, A2;               
    scanf("%s %lf %d %s %lf %d", N1, &H1, &A1, N2, &H2, &A2);
    printf("Name 1: %s\n", N1);
    printf("Height 1: %.2lf\n", H1);
    printf("Age 1: %d\n", A1);
    printf("Name 2: %s\n", N2);
    printf("Height 2: %.2lf\n", H2);
    printf("Age 2: %d\n", A2);
    return 0;
}