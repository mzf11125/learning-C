#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 100

// Function to merge two subarrays of dictionary
void merge(char dictionary[MAX_WORDS][2][MAX_WORD_LENGTH], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1][2][MAX_WORD_LENGTH], R[n2][2][MAX_WORD_LENGTH];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        strcpy(L[i][0], dictionary[left + i][0]);
        strcpy(L[i][1], dictionary[left + i][1]);
    }
    for (j = 0; j < n2; j++) {
        strcpy(R[j][0], dictionary[mid + 1 + j][0]);
        strcpy(R[j][1], dictionary[mid + 1 + j][1]);
    }

    // Merge the temporary arrays back into dictionary[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i][0], R[j][0]) <= 0) {
            strcpy(dictionary[k][0], L[i][0]);
            strcpy(dictionary[k][1], L[i][1]);
            i++;
        } else {
            strcpy(dictionary[k][0], R[j][0]);
            strcpy(dictionary[k][1], R[j][1]);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        strcpy(dictionary[k][0], L[i][0]);
        strcpy(dictionary[k][1], L[i][1]);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        strcpy(dictionary[k][0], R[j][0]);
        strcpy(dictionary[k][1], R[j][1]);
        j++;
        k++;
    }
}

// Main function to perform merge sort on dictionary
void mergeSort(char dictionary[MAX_WORDS][2][MAX_WORD_LENGTH], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(dictionary, left, mid);
        mergeSort(dictionary, mid + 1, right);

        // Merge the sorted halves
        merge(dictionary, left, mid, right);
    }
}

// Function to translate a sentence according to the dictionary
void translateSentence(char dictionary[MAX_WORDS][2][MAX_WORD_LENGTH], int dictionarySize, char sentence[MAX_SENTENCE_LENGTH]) {
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < dictionarySize; ++i) {
            if (strcmp(token, dictionary[i][0]) == 0) {
                printf("%s ", dictionary[i][1]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    // Read the dictionary
    int T;
    fscanf(stdin, "%d", &T);
    
    char dictionary[MAX_WORDS][2][MAX_WORD_LENGTH];
    for (int i = 0; i < T; ++i) {
        fscanf(stdin, "%[^#]#%s", dictionary[i][0], dictionary[i][1]);
    }

    
//    mergeSort(dictionary, 0, T - 1);

    // Read the number of test cases
    int TC;
    fscanf(stdin, "%d", &TC);
    
    // Read and translate each test case
    char sentence[MAX_SENTENCE_LENGTH];
    for (int i = 0; i < TC; ++i) {
        fscanf(stdin, " %[^\n]s", sentence);
        printf("Case #%d:\n", i + 1);
        translateSentence(dictionary, T, sentence);
    }

    return 0;
}
