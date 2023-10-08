#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    double results[T]; 
        
    for (int i = 0; i < T; i++) {
        int P, N;
        scanf("%d %d", &P, &N);
    
        if (P >= 1 && P <= 100 && N >= 1 && N <= 2147483647) { 
            double result = (P/100.0) * N;
            results[i] = result;
        } else {
            printf("Invalid input\n");
            return 1;
        }
    }
        
        
    for (int i = 0; i < T; i++) {
        printf("%.2lf\n", results[i]);
    }
   
    return 0;
}
