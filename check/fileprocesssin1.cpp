//fileprocessing.cpp
#include <stdio.h>
#include <string.h>

FILE* files = fopen("data2.txt", "r");

struct orders{
	
	int qty;
	char makanan[100];
	char minuman[100];
	
	
	
};

int main()
{
     if(files == NULL) {
         printf("File not found\n");
     }
     else if (files != NULL)
     {
         char str[100];
         while(fgets(str, 100, files) != NULL) {//Belum abis, print semua
             printf("%s", str);
         }
         struct orders ord[100];
         
         
     }
     
    char strings[1000];
//    fscanf(files,"%[^\n]\n", strings);
//    printf("%s\n", strings);
    fclose(files);
    return 0;
}