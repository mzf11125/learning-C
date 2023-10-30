#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        
        char S[N + 1];
        scanf(" %[^\n]s", S);
        
        char modifiedS[N + 1];
        int j = 0;

        for (int i = 0; i < N; i++) {
            if (isalpha(S[i])) { 
                modifiedS[j++] = S[i];
            }
        }

        modifiedS[j] = '\0'; 
        
        printf("Case #%d: %s\n", t, modifiedS);
    }

    return 0;
}
