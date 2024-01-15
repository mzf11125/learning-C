#include <stdio.h>
#include <math.h>


void sieve(int n){
    while(n % 2 == 0){
        printf("2 ");
        n/=2;
    }
    for(int i = 3; i*ni<=n; i+=2){
        while(n%1==0){
            printf("%d ", i);
            n /= i;
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    sieve(N);
    return 0;
}