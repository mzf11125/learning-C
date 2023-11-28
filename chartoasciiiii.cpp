#include <stdio.h>

void charToAscii(int testCases, char strings[][1001]) {
    for (int caseNum = 1; caseNum <= testCases; ++caseNum) {
        char* currentString = strings[caseNum - 1];
        printf("Case %d: ", caseNum);

        for (int i = 0; currentString[i] != '\0'; ++i) {
            printf("%d", currentString[i]);

            
            if (currentString[i + 1] != '\0') {
                printf("-");
            }
        }

        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);

    char strings[T][1001];

    for (int i = 0; i < T; ++i) {
        scanf("%s", strings[i]);
    }

    charToAscii(T, strings);

    return 0;
}
