#include <stdio.h>
#include <string.h>

struct data {
    char title[1005];
    char name[1005];
    long long view;
};

//function merge sort
void merge(struct data arr[], int left, int right) {
    int mid = (left + right) / 2;
    struct data sortedlist[right - left + 1];
    int count = 0;
    int leftindex = left;
    int rightindex = mid + 1;

    while (leftindex <= mid && rightindex <= right) {
        if (arr[leftindex].view == arr[rightindex].view) {

            if (strcmp(arr[leftindex].title, arr[rightindex].title) < 0) {
                sortedlist[count] = arr[leftindex];
                count++, leftindex++;
            } else {
                sortedlist[count] = arr[rightindex];
                count++, rightindex++;
            }

        } else if (arr[leftindex].view < arr[rightindex].view) {
            sortedlist[count] = arr[rightindex];
            count++, rightindex++;
        } else {
            sortedlist[count] = arr[leftindex];
			count++, leftindex++;
        }
    }

    while (leftindex <= mid) {
        sortedlist[count] = arr[leftindex];
        count++, leftindex++;
    }
    while (rightindex <= right) {
        sortedlist[count] = arr[rightindex];
        count++, rightindex++;
    }

    for (int i = 0; i < count; i++) {
        arr[left + i] = sortedlist[i];
    }
}

void mergeSort(struct data arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        // divide data
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // merge data and sort
        merge(arr, left, right);
    }
}

int main() {

    FILE *file;
    file = fopen("testdata.in", "r");
    struct data listdata[1005];
	int size = 0;
	int i = 0;
    while (!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%lld\n", listdata[i].title, listdata[i].name, &listdata[i].view);
        i++;
    }
    
    size = i;
    fclose(file);

    mergeSort(listdata, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%s by %s - %lld\n", listdata[i].title, listdata[i].name, listdata[i].view);
    }

    return 0;
}

