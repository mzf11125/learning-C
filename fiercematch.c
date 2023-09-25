#include <stdio.h>

int main(){
    char input[100];
    int X, Y, N;
    char operator;

    scanf("%d %c %d", &X, &operator, &Y);

    if (operator == '+')
    {
        N = X + Y;
        printf("%d\n", N);
    } else 
    {
        printf("Operator not found\n");
        return 1;
    }
    

    return 0;
}