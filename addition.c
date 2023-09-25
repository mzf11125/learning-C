#include <stdio.h>

int main() {
    int A[3], B[3], C[3];
    char OPERATOR[3];
    
    for (int i = 0; i < 3; i++) {
        
        int validInput = scanf("%d %c %d =", &A[i], &OPERATOR[i], &C[i]);
        
        if (validInput != 3 || OPERATOR[i] != '+') {
            printf("Invalid input format\n");
            return 1; 
        }

        if (A[i] < -100000 || A[i] > 100000 || C[i] < -100000 || C[i] > 100000) {
            printf("Numbers must be between -100000 and 100000\n");
            return 1;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        B[i] = A[i] + C[i];
    }
    
    
    for (int i = 0; i < 3; i++) {
        printf("%d\n", B[i]);
    }
    
    return 0;
}
