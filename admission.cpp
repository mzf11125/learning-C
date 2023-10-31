#include <stdio.h>

int main(){
    char name[101];
    int age;

    scanf("%100s", name);
    scanf("%d", &age);

    printf("Halo nama saya %s dan umur saya %d", name, age);

    return 0;
}
