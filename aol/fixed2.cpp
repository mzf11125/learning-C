#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char *COLUMN_NAMES[] = {"Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish"};

struct Data {
    char location[5005];
    char city[5005];
    int price;
    int room;
    int bathroom;
    int carpark;
    char type[5005];
    char furnish[5005];
} listData[10005];

struct SearchResult {
    struct Data *data;
    int count;
};

void displayData(struct Data *dataArr, int rows) {
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");

    for (int i = 0; i < rows; i++) {
        printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
               dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
               dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
    }
}

int validate_column(const char *column) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(column, COLUMN_NAMES[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

struct SearchResult searchStringTarget(struct Data *dataArr, char *query, char *target) {
    int foundCount = 0;
    struct Data foundData[10005];
    for (int i = 0; i < 10005; i++) {
        if (strcmp(query, COLUMN_NAMES[0]) == 0) {
            if (strcmp(dataArr[i].location, target) == 0) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        } else if (strcmp(query, COLUMN_NAMES[1]) == 0) {
            if (strcmp(dataArr[i].city, target) == 0) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        } else if (strcmp(query, COLUMN_NAMES[6]) == 0) {
            if (strcmp(dataArr[i].type, target) == 0) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        } else if (strcmp(query, COLUMN_NAMES[7]) == 0) {
            if (strcmp(dataArr[i].furnish, target) == 0) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }
    }
    struct SearchResult searchRes;
    searchRes.data = foundData;
    searchRes.count = foundCount;

    return searchRes;
}

struct SearchResult searchNumberTarget(struct Data *dataArr, char *query, long long target) {
    int foundCount = 0;
    struct Data foundData[10005];
    for (int i = 0; i < 10005; i++) {
        if (strcmp(query, COLUMN_NAMES[2]) == 0) {
            if (dataArr[i].price == target) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        } else if (strcmp(query, COLUMN_NAMES[3]) == 0) {
            if (dataArr[i].room == target) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        } else if (strcmp(query, COLUMN_NAMES[4]) == 0) {
            if (dataArr[i].bathroom == target) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        } else if (strcmp(query, COLUMN_NAMES[5]) == 0) {
            if (dataArr[i].carpark == target) {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }
    }
    struct SearchResult searchRes;
    searchRes.data = foundData;
    searchRes.count = foundCount;

    return searchRes;
}

void searchFunction(struct Data *dataArray) {
    char searchQuery[5005];
    while (true) {
        printf("Choose column: ");
        scanf("%s", searchQuery);
        if (validate_column(searchQuery)) {
            break;
        }
        printf("Invalid column\n");
    }

    struct SearchResult searchRes;

    if (strcmp(searchQuery, COLUMN_NAMES[0]) == 0 || strcmp(searchQuery, COLUMN_NAMES[1]) == 0 ||
        strcmp(searchQuery, COLUMN_NAMES[6]) == 0 || strcmp(searchQuery, COLUMN_NAMES[7]) == 0) {
        char searchTarget[5005];
        printf("What data do you want to find? ");
        scanf("%s", searchTarget);
        searchRes = searchStringTarget(dataArray, searchQuery, searchTarget);
    } else {
        long long searchTargetNum;
        printf("What data do you want to find? ");
        scanf("%lld", &searchTargetNum);
        searchRes = searchNumberTarget(dataArray, searchQuery, searchTargetNum);
    }

    if (searchRes.count == 0) {
        printf("Not Found\n");
    } else {
        printf("Data found. Detail of data:\n");
        displayData(searchRes.data, searchRes.count);
    }
}

int main() {
    FILE *f = fopen("file.csv", "r");
    char filename[5005];
    int size = 0;
    fscanf(f, "%[^\n]\n", filename);

    while (!feof(f) && size < 10005) {
        fscanf(f, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", listData[size].location, listData[size].city, &listData[size].price, &listData[size].room, &listData[size].bathroom, &listData[size].carpark, listData[size].type, listData[size].furnish);
        size++;
    }

    int choice = 0;
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
            case 1:
                int rows;
                printf("Number of rows: ");
                scanf("%d", &rows);
                displayData(listData, rows);
                break;
            case 2:
                searchFunction(listData);
                break;
            case 3:
                // Implement sort function
                break;
            case 4:
                // Implement export function
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    fclose(f);

    return 0;
}
