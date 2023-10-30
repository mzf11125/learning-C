#include <stdio.h>
#include <string.h>

int isLowerCaseAlphabet(char c) {
    return (c >= 'a' && c <= 'z');
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        char S[N + 1];
        scanf(" %[^\n]s", S); // Read the string with spaces

        // Check if the string contains at least one alphabet character
        int containsAlphabet = 0;
        for (int i = 0; i < N; i++) {
            if (isLowerCaseAlphabet(S[i])) {
                containsAlphabet = 1;
                break;
            }
        }

        if (containsAlphabet) {
            char modifiedS[N + 1];
            int j = 0;

            for (int i = 0; i < N; i++) {
                if (isLowerCaseAlphabet(S[i])) { // Check if it's a lowercase alphabet character
                    modifiedS[j++] = S[i];
                }
            }

            modifiedS[j] = '\0'; // Null-terminate the modified string

            printf("Case #%d: %s\n", t, modifiedS);
        }
    }

    return 0;
}
