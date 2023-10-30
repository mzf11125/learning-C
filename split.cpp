#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        
        int nums[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }
        
        int leftSum = 0;
        int rightSum = 0;
        int isPossible = 0;
        
        for (int i = 0; i < N; i++) {
            leftSum += nums[i];
            rightSum = 0;
            
            for (int j = i + 1; j < N; j++) {
                rightSum += nums[j];
            }
            
            if (leftSum == rightSum) {
                isPossible = 1;
                break;
            }
        }
        
        if (isPossible) {
            printf("Case #%d: Yes\n", t);
        } else {
            printf("Case #%d: No\n", t);
        }
    }
    
    return 0;
}
