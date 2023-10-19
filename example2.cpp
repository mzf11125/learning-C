#include <stdio.h>

void passbyValue(int *num){
    *num *= 2;
    // *num = *num *2
}

int main()
{
    int data = 5;
    passbyValue(&data);
    printf("%d", data);

    return 0;
}
