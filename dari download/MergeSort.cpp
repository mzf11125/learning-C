#include <stdio.h>

void sort(int arr[], int left, int mid, int right){
    int l1 = mid - left + 1;
    int r1 = right - mid;
    int L[l1],R[r1];

    for(int k=0;k<l1;k++){
        L[k] = arr[left+k];
    }
    for(int k=0;k<r1;k++){
        R[k] = arr[mid + 1 + k];
    }
    int i,j,k;
    i = 0;j = 0;k = left;
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
    while(i < l1){
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < r1){
        arr[k] = R[j];
        k++;
        j++;
    }
}

/*

*/

void merge(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        merge(arr,left,mid);
        merge(arr,mid+1,right);

        sort(arr,left,mid,right);
    }
}


void mergeSort(int arr[], int l, int size){
    merge(arr,0,size-1);
}

int main(){
    int N;
    scanf("%d",&N);getchar();
    int arr[N+1];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,N);
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;   
}