//fileprocessing.cpp
#include <stdio.h>
#include <string.h>

FILE* file = fopen("test.txt", "r");;

int main()
{
    // file = fopen("data.txt", "w"); Open file
    if(file == NULL) {
        printf("File not found\n");
    }
    else if (file != NULL)
    {
        printf("File found\n");
        char str[100];
        while(fgets(str, 100, file) != NULL) {
            printf("%s", str);
        }
        fclose(file);
    }
    
    
    // int a, b;
    // scanf("%d %d", &a, &b);
    // printf("%d", a+b);
    // return 0;
}


