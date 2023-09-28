#include <stdio.h>

int main()
{
    long long X, Y, Z;
    scanf("%lld %lld %lld", &X, &Y, &Z);

    if (X == Z && Y == Z) {
        printf("1\n");
    }
    else {
        printf("-1\n");
    }

    return 0;
}