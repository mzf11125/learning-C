#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

 
    char c[T][T];


    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            scanf(" %c", &c[i][j]);  
        }
    }

    
    for (int i = T - 1; i >= 0; i--) {
        for (int j = T - 1; j >= 0; j--) {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

