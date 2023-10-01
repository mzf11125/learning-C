#include <stdio.h>

int main() {
    int T;
    
    scanf("%d", &T);
    
    int A[T], B[T]; 
    
    
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A[i], &B[i]);
        getchar();
    }
    char result[50]; 
    
    for (int i = 0; i < T; i++) {
        int X = A[i] * B[i]; 
        if (X % 2 == 0) {
            sprintf(result, "Case #%d: Party time!", i + 1);
        }
        else {
            sprintf(result, "Case #%d: Need more frogs", i + 1);
        }
        printf("%s\n", result);
    }

    return 0;
}

//This code is bwoken