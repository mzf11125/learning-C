#include <stdio.h>

// Function to find the smallest lexicographical order word
void findSmallestWord(int N) {
    char word[27];
    for (int i = 0; i < N; i++) {
        word[i] = 'a' + i;
    }
    word[N] = '\0';

    printf("Case #%d: %s\n", N, word);
}

int main() {
    int T;  // Number of test cases
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;  // Number of alphabets
        scanf("%d", &N);
        findSmallestWord(N);
    }

    return 0;
}
