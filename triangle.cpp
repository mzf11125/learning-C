#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        int N;
        scanf("%d", &N);

        printf("Case #%d:\n", case_num);

        // Loop to build the triangle
        for (int i = 1; i <= N; i++) {
            // Loop to print '#' symbols
            for (int j = 1; j <= i; j++) {
                printf("#");
            }

            // Loop to print '*' symbol
            printf("*");

            printf("\n");
        }

        // Add a newline between test cases
        if (case_num < T) {
            printf("\n");
        }
    }

    return 0;
}
