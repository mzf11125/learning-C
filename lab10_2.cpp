#include <stdio.h>

int main() {
//	FILE *inputFile = fopen("testdata3.txt", "r");
    FILE *inputFile = fopen("testdata.in", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int T;
    fscanf(inputFile, "%d", &T);

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int N, A, B;
        fscanf(inputFile, "%d %d %d", &N, &A, &B);

        char binaryString[N + 1];
        fscanf(inputFile, "%s", binaryString);

        int lightningCount = 0;

        for (int i = 0; i < N; ++i) {
            int duration = 0;
            while (i < N && binaryString[i] == '1') {
                ++duration;
                ++i;
            }

            if (duration >= A && duration <= B) {
                ++lightningCount;
            }
        }

        printf("Case #%d: %d\n", caseNum, lightningCount);
    }

    fclose(inputFile);

    return 0;
}
