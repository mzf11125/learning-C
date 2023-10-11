#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int results[T]; // Store the results for all test cases

    for (int caseNum = 0; caseNum < T; caseNum++) {
        int N, M;
        scanf("%d %d", &N, &M);

        int prices[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &prices[i]);
        }

        int maxCandy = 0;
        for (int i = 0; i < N; i++) {
            int numCandy = M / prices[i];
            if (numCandy > maxCandy) {
                maxCandy = numCandy;
            }
        }

        results[caseNum] = maxCandy; 
    }

    for (int caseNum = 0; caseNum < T; caseNum++) {
        printf("Case #%d: %d\n", caseNum + 1, results[caseNum]);
    }

    return 0;
}
