#include <stdio.h>

int main() {
    int t, a, b, i;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d %d", &a, &b);
        printf("Case #%d: ", i);
        if (a == b) {
            printf("NO\n");
            continue;
        }
        if (a == 1) {
            a++;
        }
        while (a < b) {
            if (b % 2 == 0 && b / 2 >= a) {
                b /= 2;
            } else {
                b = b * 3 + 1;
            }
        }
        if (a == b) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
