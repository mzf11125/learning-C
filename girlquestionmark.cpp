#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        char S[100001];
        scanf("%s", S);

        int distinct_chars = 0;
        int char_count[26] = {0};  

        for (int j = 0; j < strlen(S); j++) {
            int index = S[j] - 'a';
            if (char_count[index] == 0) {
                distinct_chars++;
                char_count[index]++;
            }
        }

        printf("Case #%d: %s\n", i, (distinct_chars % 2 == 0) ? "Yay" : "Ewwww");
    }

    return 0;
}
