#include <stdio.h>

int main() {
    int X, Y, T;

    scanf("%d %d", &X, &Y);


    int garden[100][100];
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            scanf("%d", &garden[i][j]);
        }
    }

    scanf("%d", &T);

    for (int k = 0; k < T; k++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a > 0 && a <= X && b > 0 && b <= Y) {
            garden[a - 1][b - 1] = c;

    
            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++) {
                    printf("%d ", garden[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Invalid input. Coordinates out of bounds.\n");
        }
    }

    return 0;
}
