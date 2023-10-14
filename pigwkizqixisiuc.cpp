#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        int N, K;
        scanf("%d %d", &N, &K);
        char S[N + 1];
        scanf("%s", S);

        for (int i = 0; i < N; i++) {
            int letter = S[i] - 'a'; 
            letter = (letter + K) % 26; 
            S[i] = 'a' + letter; 
        }

        printf("Case #%d: %s\n", case_num, S);
    }

    return 0;
}
