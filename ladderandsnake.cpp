#include <stdio.h>

int main() {
    int N, total = 0;


    scanf("%d", &N);
	if (N < 1 || N > 2000) {
        printf("N is out of range (1 = N = 2000)\n");
        return 1; 
    }
 
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        

       
        total += k;

      
        if (total == 9) {
            total = 21;
        } else if (total == 33) {
            total = 42;
        } else if (total == 76) {
            total = 92;
        } else if (total == 53) {
            total = 37;
        } else if (total == 80) {
            total = 59;
        } else if (total == 97) {
            total = 88;
        }
    }

 
    printf("%d\n", total);

    return 0;
}
