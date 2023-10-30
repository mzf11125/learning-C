#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        
        int nums[N];
        int totalSum = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
            totalSum += nums[i];
        }
        
        int leftSum = 0;
        int isPossible = 0;
        
        for (int i = 0; i < N; i++) {
            if (leftSum == totalSum - leftSum) {
                isPossible = 1;
                break;
            }
            
            leftSum += nums[i];
        }
        
        if (isPossible) {
            printf("Case #%d: Yes\n", t);
        } else {
            printf("Case #%d: No\n", t);
        }
    }
    
    return 0;
}
