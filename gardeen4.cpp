#include <stdio.h>

int main() {
    int X, Y;
    
    scanf("%d %d", &X, &Y);

    int garden[X][Y];
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            scanf("%d", &garden[i][j]);
        }
    }

    int T;
    scanf("%d", &T);

    for (int k = 0; k < T; k++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        garden[a - 1][b - 1] = c;
    }

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%d ", garden[i][j]);
        }
        printf("\n");
    }

    return 0;
}