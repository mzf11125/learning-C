#include <stdio.h>

int main()
{
    char id[11], name[100];
    char class; 
    int num;
    
    scanf("%10s", id);
    scanf("%99s", name);
    

    scanf(" %c", &class); 
    
    
    scanf(" %[^\n]", name);
    
    
    scanf(" %c %d", &class, &num); 

    printf("Id    : %s\n", id);
    printf("Name  : %s\n", name);
    printf("Class : %c\n", class);
    printf("Num   : %d\n", num);

    return 0;
}
