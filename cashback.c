#include <stdio.h>

int main() {
    int T;
    
    scanf("%d", &T);
    
    int A[T], B[T];  
    
    for (int i = 0; i < T; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
    
    for (int i = 0; i < T; i++){
        if (A[i] != B[i]) {
            char result[20];  
            if (A[i] > B[i]){
                sprintf(result, "Case #%d: Go-Jo", i + 1);
            }
            else{
                sprintf(result, "Case #%d: Bi-Pay", i + 1);
            }
            printf("%s\n", result);
        }
        else{
            printf("Case #%d: A and B must not be equal.\n", i + 1);
        }  
    }

    return 0;
}
