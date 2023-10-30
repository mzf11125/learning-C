#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        printf("Case %d:", i);

        int pieces = 1;
        int cuts = 0;
        
        while (cuts < N) {
            printf(" %d", pieces);
            cuts++;
            pieces += cuts;
        }

        printf("\n");
    }

    return 0;
}
