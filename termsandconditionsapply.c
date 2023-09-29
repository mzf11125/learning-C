#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    if (T >= 1 && T <= 1000) {  
        char results[T][100];  

        for (int t = 0; t < T; t++) {
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);

            if (A % 100 == 0 && C >= 1 && C <= 1000000) {  
                int cashback = (A * B) / 100;
                if (cashback > C) {
                    cashback = C;
                }
                sprintf(results[t], "Case #%d: %d\n", t + 1, cashback);
            } else {
                sprintf(results[t], "Invalid input for case #%d\n", t + 1);
            }
        }

        for (int t = 0; t < T; t++) {
            printf("%s", results[t]);
        }
    } else {
        printf("Invalid value of T\n");
    }

    return 0;
}
