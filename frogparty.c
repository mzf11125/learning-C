#include <stdio.h>

int main() {
    int T;
    
    scanf("%d", &T);
    
    int A[T], B[T]; 
    long long multiplication[T]; 
    
    
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A[i], &B[i]);
        multiplication[i] = (long long)A[i] * B[i]; 
    }
    
    for (int i = 0; i < T; i++) {
        if (A[i] != B[i]) {
            char result[40];  
            if (multiplication[i] % 2 == 0) {
                sprintf(result, "Case #%d: Party time!", i + 1);
            }
            else {
                sprintf(result, "Case #%d: Need more frogs", i + 1);
            }
            printf("%s\n", result);
        }
        else {
            printf("Case #%d: A and B must not be equal.\n", i + 1);
        }  
    }

    return 0;
}
