#include <stdio.h>

int main() {
    char myChar1, myChar2;
    
    scanf(" %c %c", &myChar1, &myChar2);
    
    int myInt = ((int)myChar1) * ((int)myChar2);

    printf("Result: %d\n", myInt);

    return 0;
}
