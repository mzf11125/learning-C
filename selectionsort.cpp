#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    temp = *b; 
}

void selectionSort(int angka[], int n){
    int min;
    for(int i = 0; i<n-1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(angka[j]<angka[min]){
                min=j;
            }
        }
        if(min!=i)swap(&angka[min], &angka[i]);
    }
}

int main(){



    return 0;
}