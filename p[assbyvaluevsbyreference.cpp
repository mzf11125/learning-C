#include <stdio.h>

void swapByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("After swap A di function= %d\n", a);
    printf("After swap b di function= %d\n", b);
}

void swapByReference(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After swap A di function= %d\n", *a);
    printf("After swap b di function= %d\n", *b);
}

int main(){
    // Two variable, a and b 
    int a = 10;
    int b = 5;
    swapByReference(&a, &b);
    printf("After A di main= %d\n", a);
    printf("After b di main= %d\n", b);
    return 0;
}