#include <stdio.h>

void Pattern(int doors[], int N, int X) {
    for (int j = X; j <= N; j += X) {
        doors[j] = !doors[j];  
    }
}

void solve(int t) {
    int N, M;
    scanf("%d %d", &N, &M);

    int doors[N + 1];
    for (int i = 1; i <= N; ++i) {
        doors[i] = 1;  
    }

    for (int i = 0; i < M; ++i) {
        int X;
        scanf("%d", &X);
        Pattern(doors, N, X);
    }

    printf("Case #%d:", t);

    int openDoors = 0;
    for (int i = 1; i <= N; ++i) {
        if (doors[i]) {
            printf(" %d", i);
            ++openDoors;
        }
    }

    if (openDoors == 0) {
        printf(" No room left!");
    }

    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        solve(t);
    }

    return 0;
}
