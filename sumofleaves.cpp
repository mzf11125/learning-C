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

        // Input the number of leaves on each branch
        for (int i = 0; i < N; i++) {
            scanf("%d", &leaves[i]);
        }

        int result = 0;

        // Calculate the number of leaves for each branch using recursion
        for (int i = 0; i < N; i++) {
            result += calculate(leaves, i);
        }

        // Output the result for the current test case
        printf("Case #%d:\n%d\n", t, result);
    }

    return 0;
}
