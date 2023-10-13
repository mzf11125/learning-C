#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int weapons[N];
    int dragonAttacks[M];

    
    for (int i = 0; i < N; i++) {
        scanf("%d", &weapons[i]);
    }

    
    for (int i = 0; i < M; i++) {
        scanf("%d", &dragonAttacks[i]);
    }

    
    int maxWeaponPower = weapons[0];
    for (int i = 1; i < N; i++) {
        if (weapons[i] > maxWeaponPower) {
            maxWeaponPower = weapons[i];
        }
    }

    
    int maxDragonPower = dragonAttacks[0];
    for (int i = 1; i < M; i++) {
        if (dragonAttacks[i] > maxDragonPower) {
            maxDragonPower = dragonAttacks[i];
        }
    }

    
    if (maxWeaponPower > maxDragonPower) {
        printf("The dark secret was true\n");
    } else {
        printf("Secret debunked\n");
    }

    return 0;
}
