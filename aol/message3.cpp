#include <stdio.h>
#include <string.h>

struct Data {
    char location[5005];
    char city[5005];
    int price;
    int room;
    int bathroom;
    int carpark;
    char type[5005];
    char furnish[5005];
};

struct Data searchData[10005];

void read_csv(const char *filename) {
    FILE *file = fopen("file.csv", "r");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    int i = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]", searchData[i].location, searchData[i].city, 
          &searchData[i].price, 
                  &searchData[i].room, 
                  &searchData[i].bathroom, 
                  &searchData[i].carpark, 
                  searchData[i].type, 
                  searchData[i].furnish);
        i++;
    }

    fclose(file);
}

void display(int n) {
    printf("Location\tCity\t\t\tPrice\t\tRooms\tBathroom\tCarpark\tType\tFurnish\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",
               searchData[i].location,
               searchData[i].city,
               searchData[i].price,
               searchData[i].room,
               searchData[i].bathroom,
               searchData[i].carpark,
               searchData[i].type,
               searchData[i].furnish);
    }
}

void select_row(const char *column, const char *query, int total_rows) {
    int count = 0;
    for (int i = 0; i < total_rows; i++) {
        if (strcmp(searchData[i].location, "EMPTY") != 0) {
            if (strcmp(column, "location") == 0 && strcmp(searchData[i].location, query) == 0) {
                printf("%s,%s,%d,%d,%d,%d,%s,%s\n",
                   searchData[i].location,
                   searchData[i].city,
                   searchData[i].price,
                   searchData[i].room,
                   searchData[i].bathroom,
                   searchData[i].carpark,
                   searchData[i].type,
                   searchData[i].furnish);
                count++;
            } else if (strcmp(column, "city") == 0 && strcmp(searchData[i].city, query) == 0) {
                printf("%s,%s,%d,%d,%d,%d,%s,%s\n",
                   searchData[i].location,
                   searchData[i].city,
                   searchData[i].price,
                   searchData[i].room,
                   searchData[i].bathroom,
                   searchData[i].carpark,
                   searchData[i].type,
                   searchData[i].furnish);
                count++;
            }
        }
    }
    if (count == 0) {
        printf("No data found.\n");
    }
}

void merge(struct Data arr[], int left, int middle, int right, const char *column) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    struct Data L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        int compare;
        if (strcmp(column, "location") == 0)
            compare = strcmp(L[i].location, R[j].location);
        else if (strcmp(column, "city") == 0)
            compare = strcmp(L[i].city, R[j].city);
        // Add conditions for other columns if needed

        if (compare <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Data arr[], int left, int right, const char *column) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle, column);
        mergeSort(arr, middle + 1, right, column);

        // Merge the sorted halves
        merge(arr, left, middle, right, column);
    }
}

void sort_by(const char *column, const char *order) {
    // Make a temporary array for sorting
    struct Data tempData[4005];
    for (int i = 1; i < 4000; i++) {
        tempData[i] = searchData[i];
    }

    // Perform Merge Sort
    mergeSort(tempData, 0, 4000 - 1, column, order);

    printf("Data found. Detail of data:\n");
    printf("Location\tCity\t\t\tPrice\t\tRooms\tBathroom\tCarpark\tType\tFurnish\n");

    int displayRows = (4000 < 10) ? 4000 : 10;

    if (strcmp(order, "asc") == 0) {
        for (int i = 0; i < displayRows; i++) {
            printf("%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",
                   tempData[i].location,
                   tempData[i].city,
                   tempData[i].price,
                   tempData[i].room,
                   tempData[i].bathroom,
                   tempData[i].carpark,
                   tempData[i].type,
                   tempData[i].furnish);
        }
    } else if (strcmp(order, "desc") == 0) {
        for (int i = displayRows - 1; i >= 0; i--) {
            printf("%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",
                   tempData[i].location,
                   tempData[i].city,
                   tempData[i].price,
                   tempData[i].room,
                   tempData[i].bathroom,
                   tempData[i].carpark,
                   tempData[i].type,
                   tempData[i].furnish);
        }
    } else {
        printf("Invalid order specified.\n");
    }
}


void export_csv(const char *filename, int total_rows) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    fprintf(file, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");

    for (int i = 0; i < total_rows; i++) {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n",
               searchData[i].location,
               searchData[i].city,
               searchData[i].price,
               searchData[i].room,
               searchData[i].bathroom,
               searchData[i].carpark,
               searchData[i].type,
               searchData[i].furnish);
    }


    fclose(file);
    printf("Data successfully written to file %s!\n", filename);
}


int main() {
    read_csv("file.csv");

    int choice;
    int totalRows = 10005; // Assuming the total number of rows

    do {
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int numRows;
                printf("Number of rows: ");
                scanf("%d", &numRows);
                display(numRows);
                break;
            }
            case 2: {
                char column[5005];
                char query[5005];

                printf("Choose column (location/city): ");
                scanf("%s", column);

                printf("What data do you want to find? ");
                scanf("%s", query);

                select_row(column, query, totalRows);
                break;
            }
            case 3: {
                char sortColumn[5005];
                char sortOrder[5005];

                printf("Choose column (location/city): ");
                scanf("%s", sortColumn);

                printf("Sort ascending or descending? ");
                scanf("%s", sortOrder);

                sort_by(sortColumn, sortOrder);
                break;
            }
            case 4: {
                char exportFilename[5005];
                printf("File name: ");
                scanf("%s", exportFilename);

                export_csv(exportFilename, totalRows);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 5);

    return 0;
}
