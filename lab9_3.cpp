#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char arr[][21], int low, int high) {
    char pivot[21];
    strcpy(pivot, arr[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

struct student {
    char nim[11];
    char name[21];
};

void student_swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

int student_partition(struct student arr[], int low, int high) {
    char pivot[11];
    strcpy(pivot, arr[high].nim);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j].nim, pivot) < 0) {
            i++;
            student_swap(&arr[i], &arr[j]);
        }
    }

    student_swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void student_quicksort(struct student arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pi = student_partition(arr, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1) {
        fprintf(stderr, "Error reading the number of students.\n");
        fclose(file);
        return 1;
    }

    struct student students[n];

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%10s %20[^\n]", students[i].nim, students[i].name) != 2) {
            fprintf(stderr, "Error reading student data.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    student_quicksort(students, 0, n - 1);

    for (int j = 0; j < n; j++) {
        printf("%s %s\n", students[j].nim, students[j].name);
    }

    return 0;
}
