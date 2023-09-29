#include <stdio.h>

int main() {
    char x1, x2, x3;
    char output[10]; 

    
    scanf(" %c %c %c", &x1, &x2, &x3);

    
    if (x1 <= x2 && x1 <= x3) {
        sprintf(output, "1 ");
        if (x2 <= x3) {
            sprintf(output + 2, "2 3");
        } else {
            sprintf(output + 2, "3 2");
        }
    } else if (x2 <= x1 && x2 <= x3) {
        sprintf(output, "2 ");
        if (x1 <= x3) {
            sprintf(output + 2, "1 3");
        } else {
            sprintf(output + 2, "3 1");
        }
    } else {
        sprintf(output, "3 ");
        if (x1 <= x2) {
            sprintf(output + 2, "1 2");
        } else {
            sprintf(output + 2, "2 1");
        }
    }

    
    printf("%s\n", output);

    return 0;
}
