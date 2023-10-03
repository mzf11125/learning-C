#include <stdio.h>

int main() {
    int N, total = 0;


    scanf("%d", &N);

 
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);

       
        total += k;

      
        if (total == 12) {
            total = 28;
        } else if (total == 35) {
            total = 7;
        } else if (total == 30) {
            total = 10;
        }


        if (total >= 40) {
            total -= 40;
        }
    }

 
    printf("%d\n", total);

    return 0;
}
