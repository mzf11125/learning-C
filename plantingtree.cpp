#include <stdio.h>
#include <string.h>

enum {
    MAX_PLANT_NAME = 41,
    MAX_PLANTS = 1005
};

typedef struct {
    int plantNumber;
    char plantName[1005];
} Plant;

//void swap(Plant *a, Plant *b) {
//    Plant temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//int partition(Plant arr[], int low, int high) {
//    char pivot[MAX_PLANT_NAME];
//    strcpy(pivot, arr[high].plantName);
//    int i = low - 1;
//
//    for (int j = low; j <= high - 1; j++) {
//        if (strcmp(arr[j].plantName, pivot) < 0) {
//            i++;
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return i + 1;
//}
//
//void quicksort(Plant arr[], int low, int high) {
//    int stack[high - low + 1];
//    int top = -1;
//
//    stack[++top] = low;
//    stack[++top] = high;
//
//    while (top >= 0) {
//        high = stack[top--];
//        low = stack[top--];
//
//        int pi = partition(arr, low, high);
//
//        if (pi - 1 > low) {
//            stack[++top] = low;
//            stack[++top] = pi - 1;
//        }
//
//        if (pi + 1 < high) {
//            stack[++top] = pi + 1;
//            stack[++top] = high;
//        }
//    }
//}

void bubble_sort(){
	
}

int main() {
    FILE *fileIn;
    fileIn = fopen("testdata1.txt", "r");
//    fileIn = fopen("testdata.in", "r");

    if (fileIn == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int N;
    fscanf(fileIn, "%d\n", &N);
    Plant plants[MAX_PLANTS];

    for (int i = 0; i < N; i++) {
        fscanf(fileIn, "%d#", &plants[i].plantNumber);
        fgets(plants[i].plantName, MAX_PLANT_NAME, fileIn);
        plants[i].plantName[strcspn(plants[i].plantName, "\n")] = '\0';
    }

    fclose(fileIn);

    quicksort(plants, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", plants[i].plantNumber, plants[i].plantName);
    }

    return 0;
}
