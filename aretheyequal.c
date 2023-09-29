#include <stdio.h>

int main()
{
    long long a,b,c,d;
    
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    
    long long multiplication = a * b;
    long long subtraction = c - d;
    
    if (multiplication == subtraction){
        printf("True");
    }
    else {
        printf("False");
    }

    return 0;
}
