#include<stdio.h>


void insertionSort(int angka[], int n){
    int key, j;
    for(int i = 1; i<n; i++){
        key=angka[i];
        j = i-1;
        while(j>=0){
            angka[j+1] = angka[j];
            j--;
        }
        angka[j+1]=key;
    }
}


int main(){
    // int tc;



    // scanf("%d", &tc);
    
    int angka[]= ;
    



    return 0;
}