//Pass by reference
#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int max(int arr[], int n){
    int max=0;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    int arr[8]={3,2,6,5,9,1,4,8};
    int n=8;
    int hasil=max(arr, n);
    printf("%d\n", hasil);
    int a=25, b=35;
    //Swap by reference
    printf("Before: %d %d\n", a, b);
    swap(&a, &b);
    printf("After: %d %d\n", a, b);

    return 0;
}