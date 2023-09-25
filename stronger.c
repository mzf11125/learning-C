#include <stdio.h>

int main() {
    int baseDamage = 100;
    int bonusDamage = 0;
    int totalDamage;
    int N; 

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        bonusDamage += 50;
    }

    totalDamage = baseDamage + bonusDamage;

    printf("Total damage after %d hits: %d\n", N, totalDamage);

    return 0;
}