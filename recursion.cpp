#include <stdio.h>

//Recursion
//Function yang manggil function itu sendiri, function dalam function.
// Base case --> kondisi yang buat
void printHello(int n){
    if(n==0 || n==0) return;//base case, to stop the recursion
    // return, keluar dari function
    // printf("Hello\n");
    printf("%d.Hello\n", n);
    printHello(--n);
}

int factorial(int n){
    if(n==1 || n==0){return 1;}
    else{
        return n * factorial(n-1);
        //retrun 5 * factorial(4)s
    }
}

int fibo(int n){
    if(n==0 || n == 1)return 1;
    else return fibo(n-2) + fibo(n-1);
}

int main(){
    printHello(5);

    //Faktorial 
    //5! = 5x 4 x 3 x 2 x 1
    //4! = 4 x 3 x 2 x 1
    //1! = 1

    int angka;
    scanf("%d", &angka);

    // for(int i = angka-1; i > 0; i--){
    //     angka *= i;
    // }
    printf("Hasil Faktorial: %d\n", factorial(angka));
    printf("Hasil Fibo: %d\n", fibo(angka));

    return 0;
}