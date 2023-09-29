#include <stdio.h>

int main()
{
    long long a,b,c,d;
    
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    
    int multiplication = a * b;
    int subtraction = c - d;
    
    if (a >= 0 && a <= 1000000 && b >= 0 && b <= 1000000 && c >= 0 && c <= 1000000 && d >= 0 && d <= 1000000){
        if (multiplication == subtraction){
            printf("True");
        }
        else {
            printf("False");
        }
    }

    return 0;
}
