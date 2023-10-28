#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, K;
        scanf("%d %d", &N, &K);

        char hallway[N + 1];
        scanf("%s", hallway);

        int breath = K;
        int stairs = 0;
        int alive = 1;

        for (int i = 0; i < N; i++) {
            if (hallway[i] == '1') {
                stairs++;
            } else {
                breath--;
            }

            if (breath == 0) {
                if (stairs == 0) {
                    alive = 0;
                    break;
                } else if (i + 1 < N) {
                    breath = K;
                }
            }
        }

        if (alive == 1) {
            printf("Case #%d: Alive\n", t);
        } else {
            printf("Case #%d: Dead\n", t);
        }
    }

    return 0;
}
