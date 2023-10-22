#include <stdio.h>

int main() {
    int T, X;
    scanf("%d", &T);

    for (int te = 1; te <= T; te++) {
        scanf("%d", &X);
        int arr[X][X];

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < X; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        printf("Case #%d:", te);
        for (int j = 0; j < X; j++) {
            int col = 0;
            for (int i = 0; i < X; i++) {
                colSum += arr[i][j];
            }
            printf(" %d", col);
        }
        printf("\n");
    }

    return 0;
}
