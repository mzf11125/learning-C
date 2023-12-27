#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char location[100];
    char city[100];
    int price;
    int room;
    int bathroom;
    int carpark;
    char type[100];
    char furnish[100];
} Data;

Data *searchData = (Data *)malloc(5000 * sizeof(Data));


int read_csv(Data searchData[]) {
    int i = 0;
    FILE *file = fopen("file.csv", "r");
    if (!file) {
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%*[^\n]\n");

    while (fscanf(file, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]", searchData[i].location, searchData[i].city, &searchData[i].price, &searchData[i].room, &searchData[i].bathroom, &searchData[i].carpark, searchData[i].type, searchData[i].furnish) == 8)
    {
        i++;
    }

    fclose(file);

    return i;
}

void display(Data searchData[], int n)
{
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish"); //Print the header of the filename
    for (int i = 0; i < n; i++) //Print the data from the file as much as the number of rows that the user inputted
    {
        printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
               searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
               searchData[i].carpark, searchData[i].type, searchData[i].furnish);
    }
}

void searchByColumn(Data searchData[], const char *column, const char *query, int total_rows)
{
    printf("Data found. Detail of data:\n");
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");

    int foundCount = 0; // Flag to check if any data is found

    for (int i = 0; i < total_rows; i++)
    {
        if (strcmp(column, "Location") == 0 && strcmp(searchData[i].location, query) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "City") == 0 && strcmp(searchData[i].city, query) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "Price") == 0 && searchData[i].price == atoi(query))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "Rooms") == 0 && searchData[i].room == atoi(query))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "Bathrooms") == 0 && searchData[i].bathroom == atoi(query))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "Carpark") == 0 && searchData[i].carpark == atoi(query))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "Type") == 0 && strcmp(searchData[i].type, query) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
        else if (strcmp(column, "Furnish") == 0 && strcmp(searchData[i].furnish, query) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom,
                   searchData[i].carpark, searchData[i].type, searchData[i].furnish);
            foundCount++;
        }
    }

    if (foundCount == 0) //If data is not found, return 0
    {
        printf("Data not found!\n");
    }
}

void merge(Data searchData[], char column[], char order[], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    Data tempLeft[leftSize], tempRight[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        tempLeft[i] = searchData[l + i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        tempRight[i] = searchData[m + 1 + i];
    }

    int le = 0, ri = 0, start = l;

    if (strcmpi(column, "location") == 0)
    {
        while (le < leftSize && ri < rightSize)
        {
            if ((strcmp(order, "asc") == 0 && strcmp(tempLeft[le].location, tempRight[ri].location) <= 0) ||
                (strcmp(order, "desc") == 0 && strcmp(tempLeft[le].location, tempRight[ri].location) >= 0))
            {
                searchData[start] = tempLeft[le];
                le++;
            }
            else
            {
                searchData[start] = tempRight[ri];
                ri++;
            }
            start++;
        }
    }
    else if (strcmp(column, "city") == 0)
    {
        while (le < leftSize && ri < rightSize)
        {
            if ((strcmp(order, "asc") == 0 && strcmp(tempLeft[le].city, tempRight[ri].city) <= 0) ||
                (strcmp(order, "desc") == 0 && strcmp(tempLeft[le].city, tempRight[ri].city) >= 0))
            {
                searchData[start] = tempLeft[le];
                le++;
            }
            else
            {
                searchData[start] = tempRight[ri];
                ri++;
            }
            start++;
        }
    }
    else if (strcmp(column, "price") == 0)
    {
        while (le < leftSize && ri < rightSize)
        {
            if ((strcmp(order, "asc") == 0 && tempLeft[le].price <= tempRight[ri].price) ||
                (strcmp(order, "desc") == 0 && tempLeft[le].price >= tempRight[ri].price))
            {
                searchData[start] = tempLeft[le];
                le++;
            }
            else
            {
                searchData[start] = tempRight[ri];
                ri++;
            }
            start++;
        }
    }
    // Add similar blocks for other columns (room, bathroom, carpark, type, furnish)
}

void mergeSort(Data searchData[], char column[], char order[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(searchData, column, order, l, m);
        mergeSort(searchData, column, order, m + 1, r);

        merge(searchData, column, order, l, m, r);
    }
}

int main()
{
	Data *searchData = (Data *)malloc(5000 * sizeof(Data));
    int choice;

    int index = read_csv(searchData);

    do
    {
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int numRows;
            printf("Number of rows: ");
            scanf("%d", &numRows);
            display(searchData, numRows);
            break;
        }
        case 2:
        {
            char column[5005];
            char query[5005];

            printf("Choose column (location/city): ");
            scanf("%s", column);

            printf("What data do you want to find? ");
            scanf("%s", query);

            searchByColumn(searchData, column, query, index);
            break;
        }
        case 3:
        {
            char sortColumn[100];
            char sortOrder[100];

            printf("Choose column (location/city): ");
            scanf("%s", sortColumn);

            printf("Sort ascending or descending? ");
            scanf("%s", sortOrder);

            mergeSort(searchData, sortColumn, sortOrder, 0, index - 1);

            for (int i = 0; i < 10; i++)
            {
                printf("%-20s%-20s%-20d%-20d%-20d%-20d%-20s%-20s\n",
                       searchData[i].location,
                       searchData[i].city,
                       searchData[i].price,
                       searchData[i].room,
                       searchData[i].bathroom,
                       searchData[i].carpark,
                       searchData[i].type,
                       searchData[i].furnish);
            }
            break;
        }
        case 4:
        {
            char exportFilename[5005];
            printf("File name: ");
            scanf("%s", exportFilename);

            // Implement or remove export_csv function
            break;
        }
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 5);

    free(searchData); // Don't forget to free allocated memory.

    return 0;
}

