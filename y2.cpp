#include <stdio.h>
#include <string.h>

int main() {
    int t, q, start, end; // Removed the unnecessary 'm' variable
    char codes[1001], temp[1001];
    scanf("%d", &t);
    getchar();

    for (int i = 1; i <= t; i++) { // Fixed the loop condition
        scanf("%d", &q);
        getchar();
        scanf("%s", codes); // Read the input string into 'codes'

        for (int j = 1; j <= q; j++) {
            strcpy(temp, codes);
            scanf("%d %d", &start, &end);
            start--;
            end--;

            for (int k = start, m = end; k <= end; k++, m--) { // Fixed the loop initialization
                codes[k] = temp[m];
            }
        }

        printf("Case #%d: %s\n", i, codes);
    }

    return 0;
}
