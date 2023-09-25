#include <stdio.h>

int main() {
    long long baseDamage = 100;
    long long bonusDamage = 50;
    long long totalDamage;
    long long N; 

    scanf("%lld", &N);

    totalDamage = (100 * N) + ((N*50)*(N-1)/2); 

    printf("%lld\n", totalDamage); 

    return 0;
}
