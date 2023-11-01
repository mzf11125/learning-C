#include <stdio.h>

int main(){
    int Q = 0;
    int N = 1;

    scanf("%d", &Q);

    for(int i = 0; i < Q; i++){
        N *= 2; // 1 =3 * 2 = 6
        N += 1; //1 = 3, 6 + 1
    }
    printf("%d\n", N);

    return 0;
}