#include <stdio.h>

int main()
{
    double X, Y;
    scanf("%lf %lf", &X, &Y);

    double division = Y * 100 / X;
    
    printf("%.4lf%%\n", division);

    return 0;
}
