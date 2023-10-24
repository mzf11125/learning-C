#include <stdio.h>
//Function
//Function Prototype
//Variable scope
//Passing by value VS reference
//Recursion
//Example of Recursion

void HelloWorld(){ // void doesn't return anything
    printf("Hello world!\n");
}

void introduce(char name[], int age){
    printf("Nama saya %s umur saya %d\n", name, age);
}

int main(){ //int return a number
    //Function
    //Sekumpulan code yang dimana akan dijalankan
    //Apabila kita memanggilnya
    // Code lebih rapih dan bisa dipanggil berkali kali
    //[return type]][function_name](parameter){
    //  code
    //}
    //HelloWorld();
    introduce("Jack", 10);
    return 0;    
}
