#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    if (0 <= A && A <= 1000 && 0 <= B && B <= 1000) {
        int subtraction = A - B;
        printf("%d\n", subtraction);
        return 0;
    } else {
        return 1;
    }
}
