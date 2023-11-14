#include <stdio.h>


int ackermann(int m, int n){
    if (m == 0){
        return n + 1;
    }
    else if (m > 0 && n == 0){
        return ackermann(m - 1, 1);
    }
    else if (m > 0 && n > 0){
        return ackermann(m - 1, ackermann(m, n - 1));
    }

    return -1;
}

int main(){
    int m, n;

    scanf("%d %d", &m, &n);
    if (m > 3 || n > 10 || m < 1 || n < 1)printf("Invalid input");

    int result = ackermann(m, n);
    printf("result: %d\n", result);

    return 0;
}