#include <stdio.h>

int main() {
    int N, M, i, j, max = -1;
    scanf("%d %d", &N, &M);
    int bag[N], remove[M];
    for (i = 0; i < N; i++) {
        scanf("%d", &bag[i]);
    }
    for (i = 0; i < M; i++) {
        scanf("%d", &remove[i]);
    }
    for (i = 0; i < N; i++) {
        int flag = 0;
        for (j = 0; j < M; j++) {
            if (bag[i] == remove[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && bag[i] > max) {
            max = bag[i];
        }
    }
    if (max == -1) {
        printf("Maximum number is -1\n");
    } else {
        printf("Maximum number is %d\n", max);
    }
    return 0;
}
