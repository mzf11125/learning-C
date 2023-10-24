#include <stdio.h>

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
    return 0;
}
