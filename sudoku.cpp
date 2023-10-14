#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int weapons[N];
    int dragonAttacks[M];


    
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d %d ", &weapons[i]);
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
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
