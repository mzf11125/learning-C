#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_COL_LENGTH 50

char data[MAX_ROWS][MAX_COLS][MAX_COL_LENGTH];
int num_rows = 0;

void read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[256];
    int row = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        // Split line into columns
        char *token = strtok(line, ",");
        int col = 0;
        while (token != NULL && col < MAX_COLS) {
            strncpy(data[row][col], token, MAX_COL_LENGTH);
            token = strtok(NULL, ",");
            col++;
        }

        num_rows++;
        row++;
    }

    fclose(fp);
}

void display(int num_rows_to_display) {
    if (num_rows_to_display > num_rows) {
        num_rows_to_display = num_rows;
    }

    printf("\n");
    for (int i = 0; i < num_rows_to_display; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
}

void select_row(char *column, char *query_value) {
    int found = 0;
    for (int i = 0; i < num_rows; i++) {
        if (strcmp(data[i][0], query_value) == 0) {  // Assuming column names are in the first row
            printf("\nData found. Detail of data:\n");
            for (int j = 0; j < MAX_COLS; j++) {
                printf("%s ", data[i][j]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nData not found!\n");
    }
}

void sort_by(char *column, char *order) {
    // Implement sorting algorithm (e.g., bubble sort, quicksort) based on chosen column and order
    // Remember to handle data types (numeric vs. string) appropriately
}

void export(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < MAX_COLS - 1; j++) {
            fprintf(fp, "%s,", data[i][j]);
        }
        fprintf(fp, "%s\n", data[i][MAX_COLS - 1]);
    }

    fclose(fp);
    printf("Data successfully written to file %s!\n", filename);
}
