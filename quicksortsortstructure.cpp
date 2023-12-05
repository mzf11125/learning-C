#include<stdio.h>
#include <string.h>

enum {
    MAX_PLANT_NAME = 41, // we add 1 on the max plant name because it is a string, so we +1 gor space. Originially it is 40
    MAX_PLANTS = 1000 // this is the max plants which is 100
};

typedef struct {// we make typdef struct so it is easier for you to call it on the file
    int nomorNumber;
    char plantName[MAX_PLANT_NAME];
} nomor;

void swap(Plant *a, Plant *b) {
    Plant temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Plant arr[], int low, int high) {
    char pivot[MAX_PLANT_NAME];
    strcpy(pivot, arr[high].plantName);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].plantName, pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(Plant arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low; 
    stack[++top] = high;

    while (top >= 0) { // while top is greateer than or equal to 0
        high = stack[top--]; //high = stack top decrement
        low = stack[top--]; // ]low = stack top decrement

        int pi = partition(arr, low, high);//int pit adalah partisi dari array

        if (pi - 1 > low) {//but if pi - 
            stack[++top] = low; //
            stack[++top] = pi - 1; //
        }

        if (pi + 1 < high) { //
            stack[++top] = pi + 1; //
            stack[++top] = high; //
        }
    }
}



int main(){
	int tc;
	scanf("%d", &tc);
	
	int arr[];
	for (int i = 0; i < tc; i++){
		scanf()
	}	
	
	
}