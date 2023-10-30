#include <stdio.h>
#include <math.h>

int Prime(int n){
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int Square(int n){
    int sqrtN = sqrt(n);
    return (sqrtN * sqrtN == n);
}
int Cube(int n){
    int cbrtN = cbrt(n);
    return (cbrtN * cbrtN * cbrtN == n);
}
int main(){
    int T;
    scanf("%d", &T);

    for (int testCase = 1; testCase <= T; testCase++) {
        int X;
        scanf("%d", &X);

        printf("Case #%d : ", testCase);
        if (Square(X)&&Cube(X)) {
            printf("square cubic");
        }
        else if (Prime(X)) {
            printf("prime");
        }
        else if (Square(X)) {
            printf("square");
        }
        else if (Cube(X)) {
            printf("cubic");
        }
        else if (!Prime(X) && !Square(X) && !Cube(X)) {
            printf("none");
        }
        printf("\n");
    }

    return 0;
}