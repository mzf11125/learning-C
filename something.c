#include <stdio.h>

int main() {
    char name1[101], name2[101];
    double height1, height2;
    int age1, age2;

    int i = 0;
    char c;

    while ((c = getchar()) != ' ') {
        name1[i] = c;
        i++;
    }
    name1[i] = '\0';

    scanf(" %lf %d", &height1, &age1);

    i = 0;

    while ((c = getchar()) != ' ') {
        name2[i] = c;
        i++;
    }
    name2[i] = '\0';

    scanf(" %lf %d", &height2, &age2);

    printf("Name 1: %s\n", name1);
    printf("Height 1: %.2lf\n", height1);
    printf("Age 1: %d\n", age1);

    printf("Name 2: %s\n", name2);
    printf("Height 2: %.2lf\n", height2);
    printf("Age 2: %d\n", age2);

    return 0;
}
