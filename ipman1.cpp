#include <stdio.h>
#include <string.h>

int isValidIPv10(const char *s) {
    int dots = 0;
    int nums = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '.') {
            dots++;
            nums = 0;

            if (i > 0 && s[i - 1] == '.')
                return 0;  // Consecutive dots are not allowed
        } else if (s[i] >= '0' && s[i] <= '9') {
            nums++;

            if (i > 0 && s[i - 1] == '0' && s[i] != '0')
                return 0;  // Leading zeros are not allowed

            if (nums > 3)
                return 0;  // Each number should have at most 3 digits
        } else {
            return 0;  // Other characters are not allowed
        }
    }

    return (dots == 4 && nums == 4) 
    ? 1 : 0;  // There should be 4 numbers
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        char S[105];
        scanf("%s", S);

        if (isValidIPv10(S)) {
            printf("Case #%d: YES\n", t);
        } else {
            printf("Case #%d: NO\n", t);
        }
    }

    return 0;
}
