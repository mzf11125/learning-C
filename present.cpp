#include <stdio.h>

int main() {
    int T, M;
    scanf("%d", &T); getchar();
    int numGifts[T]; 

    for (int caseNum = 0; caseNum < T; caseNum++) {
        scanf("%d", &M);
        
        int highestScore = 0;
        int numGiftsCase = 0; 

        for (int j = 0; j < M; j++) {
            int score;
            scanf("%d", &score);

            if (score > highestScore) {
                highestScore = score;
                numGiftsCase = 1;
            } else if (score == highestScore) {
                numGiftsCase++;
            }
        }

        numGifts[caseNum] = numGiftsCase; 
    }

    for (int caseNum = 0; caseNum < T; caseNum++) {
        printf("Case #%d: %d\n", caseNum + 1, numGifts[caseNum]);
    }

    return 0;
}
