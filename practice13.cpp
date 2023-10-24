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
                printf("%d ", numero[i][j]);
            }
            else{
                printf("%d ", numero[i][j]);
            }
        }
        printf("\n");
    }




    return 0;
}
