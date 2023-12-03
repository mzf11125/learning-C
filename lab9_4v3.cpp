#include <stdio.h>
#include <string.h>

void generateFibonacci(int n, char s0, char s1) {
    char result[100]; // Assuming maximum length for the Fibonacci sequence
    result[0] = s0;
    result[1] = s1;

    for (int i = 2; i <= n; ++i) {
        result[i] = result[i - 1];
        int len = strlen(result);
        for (int j = 0; j < len; ++j) {
            result[i + j] = result[j];
        }
        result[i + len] = '\0';
    }

    printf("%s", result);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        int n;
        char s0, s1;
        scanf("%d %c %c", &n, &s0, &s1);

        printf("Case #%d: ", i);
        generateFibonacci(n, s0, s1);
        printf("\n");
    }

    return 0;
}
