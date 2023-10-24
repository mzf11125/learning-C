#include <stdio.h>

//Recursion
//Function yang manggil function itu sendiri, function dalam function.
// Base case --> kondisi yang buat
void printHello(int n){
    if(n==0) return;//base case, to stop the recursion
    // return, keluar dari function
    // printf("Hello\n");
    printf("%d.Hello\n", n);
    printHello(--n);
}



int main(){
    printHello(5);
    
    return 0;
}