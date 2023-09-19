#include <stdio.h>

int main()
{
    char name[105], nis[10];
    int age;
    scanf("%[^\n]s", name);
    scanf("%s %d", nis, &age);
    printf("Name: %s\n", name);
    printf("NIS: %s\n", nis);
    printf("Age: %d\n", age);
    return 0;
}