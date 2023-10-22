#include<stdio.h>

int main(){
    int testcase;
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        // 1 testcase
        int childrenCount, chocolateCount;
        scanf("%d %d", 
            &childrenCount, &chocolateCount);

        long long  takenCount = 0;
        for (int j = 0; j < childrenCount; j++) {
            // mencari coklat terbesar setiap anak
            int weights[chocolateCount];

            for (int k = 0; k < chocolateCount; k++) {
                scanf("%d", &weights[k]);
            }

            int largest = 0;
            for (int k = 0; k < chocolateCount; k++) {
                if (weights[k] > largest) {
                    largest = weights[k];
                }
            }

            takenCount = largest + takenCount;
        }

        printf("Case #%d: %lld\n", i + 1, takenCount);
    }

    return 0;
}