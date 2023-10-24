#include <stdio.h>
#include <string.h>

int main(){
    //Ptr
    int a, *ptr = &a;
    ptr = &a;
    a = 10;
    printf("%d\n", *ptr);
    *ptr = 20;
    printf("%d\n", a);

    //Ptr to ptr
    int **ptr_ptr;
    ptr_ptr = &ptr;
    printf("%d\n", **ptr_ptr);
    **ptr_ptr = 30;
    printf("%d\n", a);

    //Array of integers 1D
    int numbers[10] = {1, 2, 3, 4, 5};
    //Initialize after declaration
    numbers[5]=100;   
    scanf("%d", &numbers[6]);
    for(int i = 0; i < 10; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    //Array of string/characters 1D
    char name[20] = "Binus University"; //Initialization
    name[3]= {'a'}; //Initialization
    printf("%s\n", name);
    scanf("%[^\n]", name);getchar();
    printf("%s\n", name);
    scanf("%[^\n]", name);getchar();
    printf("%s\n", name);
    scanf("%[^\n]", name);getchar();

    //Array of integers 2D
    int numero[3][4]={{1,2,3,4},{5,6,7}};// Initialization during declaration
    //1 2 3 4
    //5 6 7 8
    //0 0 0 0
    numero[1][3]=8;
    scanf("%d", &numero[2][0]);
    for(int i = 0; i < 3; i++){//Rows
        for(int j = 0; j < 4; j++){//Columns
            if (!numero[i][j])//If the value is 0, then input other ways is if(numero[i][j] == 0) or if(!numero[i][j])
            {
                scanf("%d ", &numero[i][j]);
                if(j==3){
                    printf("%d", numero[i][j]);
                }
                else{
                    printf("%d ", numero[i][j]);
                }
            }
            else{
                if(j==3){
                    printf("%d", numero[i][j]);
                }
                else{
                    printf("%d ", numero[i][j]);
                }
            }
        }
        printf("\n");
    }

    //Array of string/characters 2D
    char names[5][20] = {"Irene", "Cassandra", "Amanda", "Bella", "Diana"};//Initialization during declaration
    //Irene Cassandra Amanda Bella Diana
    strcpy(names[2], "samuel");//Initialization after declaration   
    for(int i = 0; i <= 2; i++){
        printf("%s\n", names[i]);
    }

    //string.h library

    //strlen
    int len = strlen(names[0]);//Length of Irene
    printf("%d\n", len);
    //strcpy= string copy some characters from one string to another
    strncpy(names[0], "Binus University", 3);//Copy 3 characters from Irene to names[0], format of strncpy(destination, source, number of characters)
    printf("%s\n", names[0]);

    //strcat= string concatenation, combine two strings
    //Binne --> Binne smart kid
    strcat(names[0], " Smart Kid");//Combine Binne and Smart Kid
    printf("%s\n", names[0]);

    //strncat= string concatenation, combine some character from string two to string one 
    //Binne Smart Kid --> Binne Smart Kid hehe
    strncat(names[0], " hehehe", 5);//Combine Binne and Smart Kid, but only 3 characters from Smart Kid
    printf("%s\n", names[0]);

    //strcmp= string comparison, compare two strings
    int result = strcmp("Irene", "Irene");//Compare Binne Smart Kid hehehe and Binne Smart Kid hehehe
    printf("%d\n", result);//If the result is 0, then the two strings are the same
    result = strcmp("jono", "budi");
    printf("%d\n", result);//If the result is 1, then the first string is bigger than the second string

    result = strcmp("budi", "jono");
    printf("%d\n", result);//If the result is -1, then the first string is smaller than the second string

    //sum of some integer from array of integer
    int score[10] = {20,32,64,58,80};
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum+=score[i];//sum = sum + score[i]
    }
    printf("%d\n", sum);
    return 0;
}
