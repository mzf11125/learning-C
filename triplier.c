#include <stdio.h>

int main(){
    long long A, B, C;
    long long triplier;
    scanf("%lld %lld %lld", &A, &B, &C);
    triplier = A * B * C;
    printf("%lld\n", triplier);
    
    return 0;
}