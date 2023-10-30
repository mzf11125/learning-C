#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int x = 1; x <= T; x++) {
        int N;
        scanf("%d", &N);
        printf("Case #%d:\n", x);

        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                if (i % 15 != 0) {
                    printf("%d Jojo\n", i);
                } else {
                    printf("%d Lili\n", i);
                }
            } else {
                printf("%d Lili\n", i);
            }
        }
    }

    return 0;
}
