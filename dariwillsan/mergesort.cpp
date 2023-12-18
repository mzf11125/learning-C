#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    // copy dulu bagian kiri dan kanannya ke temporary array
    // buat iterator itu 3
    // i untuk kiri
    // j untuk kanan
    // k untuk array asli(int arr[])
    // panjang kirinya berapa
    // panjang kanannya berapa
    int l1 = mid - left + 1;
    int r1 = right - mid;
    // temporary array
    int L[l1+1], R[r1+1];
    // tiba" aslab kita jahat ada string
    // char L[l1+1][1000], R[r1+1][1000];
    // char array of array , string array, char 2d array
    // pindahin data dari array asli ke temp array
    for(int k=0;k<l1;k++){
        L[k] = arr[left + k];
    }
    for(int k=0;k<r1;k++){
        R[k] = arr[mid + 1 + k];
    }
    // konsep 3 iterator
    // i,j,k
    int i,j,k;
    i = j = 0;
    k = left;
    while(i < l1 && j < r1){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // cek jika ada sisa masihan
    // sisa kiri
    while(i < l1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // sisa kanan
    while(j < r1){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    // memecah menjadi kiri dan kanannya terus terusan

    if(left < right){
        // lakukan partisi jika kiri dan kanannya masih tidak sama dan kiri kurang dari kanan
        int mid = (left + right) >> 1; // valid juga
        mid = left + (right - left)/2;

        // partisi kiri
        mergeSort(arr,left,mid);
        // partisi kanan
        mergeSort(arr,mid+1,right);
        // membagi kiri kanan cuma sampai sini
        // panggil fungsi merge
        merge(arr,left,mid,right);
    }
}


int main(){
    int arr[] = {6,9,4,2,0,1,3,5,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    // size itu index 1 ukurannya
    // kita butuh accessing arranya index 0
    printf("Before: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    mergeSort(arr,0,size-1);
    printf("\nAfter: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}