#include <stdio.h>

int main() {
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        if (A != B) {
            int print;
            if (A > B){
                printf("Case #%d: Go-Jo", T);
            }
            else{
                printf("Case #%d: Bi-Pay", T);    
            }
        }
        else{
            printf("A and B must not be equal.");
        }
    }
    

    return 0;
}