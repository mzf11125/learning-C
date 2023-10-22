#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
        int R, H;
        scanf("%d %d", &R, &H);

        double surfaceArea = 2 * 3.14 * R * (R + H);
        
        printf("Case #%d: %.2lf\n", caseNumber, surfaceArea);
    }

    return 0;
}
