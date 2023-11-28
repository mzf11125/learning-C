#include <stdio.h>

int calculate(int leaves[], int index) {
    if (index < 0) {
        return 0;
    }

    return leaves[index] + calculate(leaves, index - 1);
}

int main() {
    int T; 
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N; 
        scanf("%d", &N);

        int leaves[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &leaves[i]);
        }

        int result = 0;

        
        for (int i = 0; i < N; i++) {
            result += calculate(leaves, i);
        }

        printf("Case #%d:\n%d\n", t, result);
    }

    return 0;
}
