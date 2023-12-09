#include <stdio.h>
#include <string.h>

void processString(char *str, char from, char to) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == from) {
            str[i] = to;
        }
    }
}

int main() {
    FILE *inputFile = fopen("testdata.in", "r");
    if (inputFile == NULL) {
        return 1;
    }

    int T;
    fscanf(inputFile, "%d", &T);

    for (int t = 0; t < T; t++) {
        char X[101];
        fscanf(inputFile, "%s", X);

        int N;
        fscanf(inputFile, "%d", &N);

        for (int n = 0; n < N; n++) {
            char from, to;
            fscanf(inputFile, " %c %c", &from, &to);
            processString(X, from, to);
        }

        // Count characters
        int count[26] = {0};
        int length = strlen(X);
        for (int i = 0; i < length; i++) {
            if (X[i] >= 'A' && X[i] <= 'Z') {
                count[X[i] - 'A']++;
            }
        }

        // Print output
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                printf("%c %d\n", 'A' + i, count[i]);
            }
        }
    }

    fclose(inputFile);

    return 0;
}
