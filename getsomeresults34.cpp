#include <stdio.h>

void multiply_matrices(int n, int a[][n], int b[][n], int c[][n]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int t, n, i, j, k;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d", &n);
        int a[n][n], b[n][n], c[n][n];
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                scanf("%d", &a[j][k]);
            }
        }
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                scanf("%d", &b[j][k]);
            }
        }
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                scanf("%d", &c[j][k]);
            }
        }
        int temp[n][n];
        multiply_matrices(n, a, b, temp);
        multiply_matrices(n, temp, c, temp);
        printf("Case #%d:\n", i);
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                printf("%d", temp[j][k]);
                if (k != n - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
