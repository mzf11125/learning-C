#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    int temperatures[T];
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &temperatures[i]);
    }
    
    for (int i = 0; i < T; i++) {
        int A = temperatures[i];
        
       
        double reaumur = A * 0.8;

    
        double fahrenheit = (A * 9.0/5.0) + 32;

    
        double kelvin = A + 273;

        printf("%.2lf %.2lf %.2lf\n", reaumur, fahrenheit, kelvin);
    }

    return 0;
}
