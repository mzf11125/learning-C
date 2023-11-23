#include <stdio.h>
//Function
//Function Prototype
//Variable scope
//Passing by value VS reference
//Recursion
//Example of Recursion
int a = 1;
int b = 3;


void function(){
    // printf("%d\n", b);
    char name[100]="Adrian";
    printf("%s\n", name);
}

int addition(int num1, int num2);//Function prototype to declare the function

void HelloWorld(){ // void doesn't return anything
    printf("Hello world!\n");
}

void introduce(char name[], int age){
    printf("Nama saya %s umur saya %d\n", name, age);
}




//Function prototype



int main(){ //int return a number
    //Function
    //Sekumpulan code yang dimana akan dijalankan
    //Apabila kita memanggilnya
    // Code lebih rapih dan bisa dipanggil berkali kali
    //[return type]][function_name](parameter){
    //  code
    //}
    //HelloWorld();
    // introduce("Jack", 10);
    printf("%d\n", addition(5, 8));
    function();

    return 0;    
}

// initialization
int addition(int num1, int num2){
    return num1+num2;
}