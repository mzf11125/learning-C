#include <stdio.h>

void drawIsoscelesTriangle(int X) {
    int i, j, k;
    for (i = 1; i <= X; i++) {

        for (j = 1; j <= X - i; j++) {
            printf(" ");
        }
        
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int T, X;
    scanf("%d", &T); 

    while (T--) {
        scanf("%d", &X); 
        drawIsoscelesTriangle(X);
        // if (T > 0) {
        //     printf("\n"); 
        // }
    }

    return 0;
}
