#include <stdio.h>

void printtriangle(int N, int case_number) {
    printf("Case #%d:\n", case_number);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j < N - 1) {
                printf(" ");
            } else {
                if ((i + j) % 2 == 0) {
                    printf("*");
                } else {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int case_number = 1; case_number <= T; case_number++) {
        int N;
        scanf("%d", &N);

        printtriangle(N, case_number);
    }

    return 0;
}
