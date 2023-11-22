#include <stdio.h>

void factorial(int n){
    if(n > 0){
        factorial(n-1); //recursive call
    }
    printf("%d", n); 
}

int main(){
    int n;

    scanf("%d", &n);
    factorial(n);

    return 0;
}