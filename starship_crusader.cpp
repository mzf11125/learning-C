#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int N; 
        scanf("%d", &N);

        int testResults[N];
        int passCriteria[N];

 
        for (int i = 0; i < N; ++i) {
            scanf("%d", &testResults[i]);
        }

     
        for (int i = 0; i < N; ++i) {
            scanf("%d", &passCriteria[i]);
        }

       
        int failedTests = 0;
        for (int i = 0; i < N; ++i) {
            if (testResults[i] < passCriteria[i]) {
                failedTests++;
            }
        }

      
        printf("Case #%d: %d\n", t, failedTests);
    }

    return 0;
}
