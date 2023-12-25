#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

//Function to display data
void displayData(struct Data *dataArr, int rows)
{
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish"); //Print the header of the filename
    for (int i = 0; i < rows; i++) //Print the data from the file as much as the number of rows that the user inputted
    {
        printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
               dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
               dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
    }
}


// Function to search data by column
void searchByColumn(struct Data *dataArr, int size, char *columnName, char *searchValue)
{
    printf("Data found. Detail of data:\n");
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");

    int foundCount = 0; // Flag to check if any data is found

    for (int i = 0; i < size; i++)
    {
        if (strcmp(columnName, "Location") == 0 && strcmp(dataArr[i].location, searchValue) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "City") == 0 && strcmp(dataArr[i].city, searchValue) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "Price") == 0 && dataArr[i].price == atoi(searchValue))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "Rooms") == 0 && dataArr[i].room == atoi(searchValue))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "Bathrooms") == 0 && dataArr[i].bathroom == atoi(searchValue))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "Carpark") == 0 && dataArr[i].carpark == atoi(searchValue))
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "Type") == 0 && strcmp(dataArr[i].type, searchValue) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
        else if (strcmp(columnName, "Furnish") == 0 && strcmp(dataArr[i].furnish, searchValue) == 0)
        {
            printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                   dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
                   dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
            foundCount++;
        }
    }

    if (foundCount == 0) //If data is not found
    {
        printf("Data not found!\n");//Print data not found
    }
}

// Function to merge two subarrays of listData[]
void merge(struct Data *arr, int l, int m, int r, char *columnName, char *ascOrDesc)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct Data *L = (struct Data *)malloc(n1 * sizeof(struct Data));
    struct Data *R = (struct Data *)malloc(n2 * sizeof(struct Data));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        int compareResult;
        if (strcmp(columnName, "Location") == 0)
            compareResult = strcmp(L[i].location, R[j].location);
        else if (strcmp(columnName, "City") == 0)
            compareResult = strcmp(L[i].city, R[j].city);
        else if (strcmp(columnName, "Price") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].price - R[j].price : R[j].price - L[i].price;
        else if (strcmp(columnName, "Rooms") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].room - R[j].room : R[j].room - L[i].room;
        else if (strcmp(columnName, "Bathrooms") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].bathroom - R[j].bathroom : R[j].bathroom - L[i].bathroom;
        else if (strcmp(columnName, "Carpark") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].carpark - R[j].carpark : R[j].carpark - L[i].carpark;
        else if (strcmp(columnName, "Type") == 0)
            compareResult = strcmp(L[i].type, R[j].type);
        else if (strcmp(columnName, "Furnish") == 0)
            compareResult = strcmp(L[i].furnish, R[j].furnish);
        else
            compareResult = 0; // Default case

        if (compareResult <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the dynamically allocated memory
    free(L);
    free(R);
}

// Main function for performing merge sort on listData[]
void mergeSort(struct Data *arr, int l, int r, char *columnName, char *ascordesc)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, columnName, ascordesc);
        mergeSort(arr, m + 1, r, columnName, ascordesc);

        // Merge the sorted halves
        merge(arr, l, m, r, columnName, ascordesc);
    }
}

// Function to export sorted data to a file
void exportToFile(struct Data *sortedData, int size, const char *filename)
{
    FILE *newfile = fopen(filename, "w");

    if (newfile == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // Print the header to the new file
    fprintf(newfile, "%-20s,%-20s,%s,%s,%s,%s,%s,%s\n",
            "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");

    // Print sorted data to the new file
    for (int i = 0; i < size; i++)
    {
        fprintf(newfile, "%-20s,%-20s,%d,%d,%d,%d,%s,%s\n",
                sortedData[i].location, sortedData[i].city, sortedData[i].price, sortedData[i].room,
                sortedData[i].bathroom, sortedData[i].carpark, sortedData[i].type, sortedData[i].furnish);
    }

    fclose(newfile);
    printf("Data exported to %s successfully.\n", filename);
}

int main()
{
    FILE *f = fopen("file.csv", "r");
    char filename[1005];
    int size = 0;
    fscanf(f, "%[^\n]\n", filename); // Read and ignore the first line

    while (!feof(f))
    {
        fscanf(f, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", listData[size].location, listData[size].city, &listData[size].price, &listData[size].room, &listData[size].bathroom, &listData[size].carpark, listData[size].type, listData[size].furnish);
        size++;
    }


    int choice = 0;
    char exportFilename[5005];
    do
    {
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);getchar();
		
        switch (choice)
        {
        case 1:
            //Display Function
        	int rows;
        	printf("Number of rows: ");
        	scanf("%d", &rows);
            displayData(listData, rows);
            break;
        case 2:
            //Search function
            {
                char columnName[5005];
                char searchValue[5005];

                printf("Choose column: ");
                scanf("%s", columnName);
                printf("What data do you want to find? ");
                scanf("%s", searchValue);

                searchByColumn(listData, size, columnName, searchValue);
            }
            break;
        case 3:
            // Sort function
            char columnName[5005];
            char ascordesc[5005];
            printf("Choose column: ");
            scanf("%[^\n]", columnName);
            getchar(); // Consume the newline character
            printf("Sort ascending or descending (asc/desc): ");
            scanf("%[^\n]", ascordesc);
            getchar(); // Consume the newline character

            // Perform merge sort
            mergeSort(listData, 0, size - 1, columnName, ascordesc);

            // Display sorted data
            printf("Sorted data:\n");
            displayData(listData, size);

            break;
        case 4:
            // Export the sorted function from case 3
            printf("Enter the filename to export sorted data: ");
            scanf("%s", exportFilename);
            // Export sorted data to a new file
            exportToFile(listData, size, exportFilename);
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
