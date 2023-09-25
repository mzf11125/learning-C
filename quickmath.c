#include <stdio.h>

int main() {
    int N; 
    
    scanf("%d", &N);
    
    if (N > 100000) {
        printf("Input exceeds the maximum limit of 100000. Please enter a smaller number.\n");
        return 1; // Exit the program with an error code
    }
    
    int addition = N + N;
    int subtraction = addition - 1;

    printf("%d plus %d is %d\nminus one is %d\n", N, N, addition, subtraction);

    return 0;
}
