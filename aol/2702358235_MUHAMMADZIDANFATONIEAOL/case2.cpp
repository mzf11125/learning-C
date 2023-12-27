#include <stdio.h>  // Import the standartd input output library
#include <string.h> // Import the string library for string functions
#include <stdlib.h> // The standard library
#include <unistd.h> // import the unistd library for the usleep functtion

// Struct of data where we will save the data from the file
struct Data
{
    char location[5005];
    char city[5005];
    int price;
    int room;
    int bathroom;
    int carpark;
    char type[5005];
    char furnish[5005];
} listData[10005]; // Declare listData is the array which uses the structure of data and where we will actually manipulate in the code

// Thank you animation
void thankYouAnimation()
{
    // Frames of the animation
    char frames[][30] = {
        "   Thank you!   ",
        "  Thank you!    ",
        " Thank you!     ",
        "Thank you!      ",
        "hank you!       ",
        "ank you!        ",
        "nk you!         ",
        "k you!          ",
        " you!           ",
        "you!            ",
        "ou!             ",
        "u!              ",
        "!               ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                "};

    int num_frames = sizeof(frames) / sizeof(frames[0]);

    // Loop to display the animation
    for (int i = 0; i < num_frames; ++i)
    {
        printf("\r%s", frames[i]);
        fflush(stdout);
        usleep(150000); // Sleep for 150 milliseconds
    }

    // Add a newline at the end
    printf("\n");
}

// Function to display data as much as the number of rows the user inputted
void displayData(struct Data *dataArr, int rows)
{
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish"); // Print the header of the filename
    for (int i = 0; i < rows; i++)                                                           // Print the data from the file as much as the number of rows that the user inputted
    {
        printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
               dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].room, dataArr[i].bathroom,
               dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish); // Print the data
    }
}

// Function to search data by column using the struct
void searchByColumn(struct Data *dataArr, int size, char *columnName, char *searchValue)
{
    printf("Data found. Detail of data:\n"); // HEre I print that data is found
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish"); // Print the variable names

    int foundCount = 0; // Flag to check if any data is found

    // Loop through the data array as much as the size of the array
    for (int i = 0; i < size; i++)
    {
        // This will check one by one for the user column input if it match with the column in the string and then will print it directly after founding it.
        // I also used foundcount++ so I can count check if data is found and if there no data found then print no data found
        // I used atoi function to convert array to integer to the search value, this is the numeric search based on the search value
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

    if (foundCount == 0) // If data is not found
    {
        printf("Data not found!\n"); // Print data not found
    }
}

// Function to merge two subarrays of listData[]
void merge(struct Data *arr, int l, int m, int r, char *columnName, char *ascOrDesc)
{
    int i, j, k;        // Declare the int
    int n1 = m - l + 1; // Declare size of the left halves
    int n2 = r - m;     // Declare size of the right halves

    // Create temporary arrays using memory allocation
    struct Data *L = (struct Data *)malloc(n1 * sizeof(struct Data));
    struct Data *R = (struct Data *)malloc(n2 * sizeof(struct Data));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Left array
    j = 0; // Right array
    k = l; //
    // Loop while current int on the left is(aka int i) is less than n1 and j
    while (i < n1 && j < n2)
    {
        int compareResult; // Declare the int to compare result
        // Check for condition if user input start with 'a' then will sort the data ascending order, else it will be descending order
        if (strcmp(columnName, "Location") == 0)
            // compareResult = strcmp(L[i].location, R[j].location);
            compareResult = ascOrDesc[0] == 'a' ? strcmp(L[i].location, R[j].location) : strcmp(R[j].location, L[i].location);
        else if (strcmp(columnName, "City") == 0)
            // compareResult = strcmp(L[i].city, R[j].city);
            compareResult = ascOrDesc[0] == 'a' ? strcmp(L[i].city, R[j].city) : strcmp(R[j].city, L[i].city);
        else if (strcmp(columnName, "Price") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].price - R[j].price : R[j].price - L[i].price;
        else if (strcmp(columnName, "Rooms") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].room - R[j].room : R[j].room - L[i].room;
        else if (strcmp(columnName, "Bathrooms") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].bathroom - R[j].bathroom : R[j].bathroom - L[i].bathroom;
        else if (strcmp(columnName, "Carpark") == 0)
            compareResult = ascOrDesc[0] == 'a' ? L[i].carpark - R[j].carpark : R[j].carpark - L[i].carpark;
        else if (strcmp(columnName, "Type") == 0)
            // compareResult = strcmp(L[i].type, R[j].type);
            compareResult = ascOrDesc[0] == 'a' ? strcmp(L[i].type, R[j].type) : strcmp(R[j].type, L[i].type);
        else if (strcmp(columnName, "Furnish") == 0)
            // compareResult = strcmp(L[i].furnish, R[j].furnish);
            compareResult = ascOrDesc[0] == 'a' ? strcmp(L[i].furnish, R[j].furnish) : strcmp(R[j].furnish, L[i].furnish);
        else
            compareResult = 0; // Default case if compare result is not found

        // If compare result is less than or equal to 0, swap current array with the left array
        if (compareResult <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        // Else, swap current array with the right array
        else
        {
            arr[k] = R[j];
            j++;
        }
        // Here we increment K where we moved to the next data in the array
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

    // Free the dynamically allocated memory so we don't get error :)
    free(L);
    free(R);
}

// The function for performing merge sort on the listData[]
void mergeSort(struct Data *arr, int l, int r, char *columnName, char *ascordesc)
{
    if (l < r) // If left is less than right
    {
        // Same as (l+r)/2, but avoids overflow for large l and r
        // Find the middle
        int m = l + (r - l) / 2;

        // Sort first and second halves
        // Left halves
        mergeSort(arr, l, m, columnName, ascordesc);
        // Right halves
        mergeSort(arr, m + 1, r, columnName, ascordesc);

        // Merge the sorted halves
        merge(arr, l, m, r, columnName, ascordesc);
    }
}

// The Function to export sorted data to a file
void exportToFile(struct Data *sortedData, int size, char *filename)
{
    char extension[5005] = ".csv";        // The string for the file extension .csv
    char FILENAME[5005];                  // Here is the filename that we saved from the filename that we got before
    strcpy(FILENAME, filename);           // We copy the string value from the previous filename to the new filename
    strcat(FILENAME, extension);          // Concatenate the 2 string into one, here we add the ".csv" file extension after the filename
    FILE *newfile = fopen(FILENAME, "w"); // Write a new file

    if (newfile == NULL) // IF there is no newfile, then print error opening file for writing
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // Print the header to the new file
    fprintf(newfile, "%-20s,%-20s,%s,%s,%s,%s,%s,%s\n",
            "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");

    // Print sorted data to the new file, comma separated :)
    for (int i = 0; i < size; i++)
    {
        fprintf(newfile, "%-20s,%-20s,%d,%d,%d,%d,%s,%s\n",
                sortedData[i].location, sortedData[i].city, sortedData[i].price, sortedData[i].room,
                sortedData[i].bathroom, sortedData[i].carpark, sortedData[i].type, sortedData[i].furnish);
    }

    fclose(newfile);                                         // Don't forget to close the file :)
    printf("Data exported to %s successfully.\n", FILENAME); // Data is written successfully
}

int main()
{
    FILE *f = fopen("file.csv", "r");
    char filename[1005];             // Declare the stringfilename which will be used to ignore the first line of the file
    int size = 0;                    // Declare size as 0
    fscanf(f, "%[^\n]\n", filename); // Read and ignore the first line

    // Scan the file while it is not the end of file
    while (!feof(f))
    {
        fscanf(f, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", listData[size].location, listData[size].city, &listData[size].price, &listData[size].room, &listData[size].bathroom, &listData[size].carpark, listData[size].type, listData[size].furnish); // Scanf the variable until coma and the end of the variable until the new line
        size++;                                                                                                                                                                                                                                         // This is to measure the size of the file
    }

    int choice = 0;            // Declare int choice as 0
    char exportFilename[5005]; // Declare the string exportfilename
    char columnName[5005];     // Declare the string columnname which user will input the column
    do
    {
        system("cls");
        // Print the menu
        printf("What do you want to do?\n"); // Ask the user what they want to do
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: "); // Print your choice
        scanf("%d", &choice);    // User input the number
        getchar();               // Get the new line

        switch (choice)
        {
        case 1:
            // Display Function
            // system("cls");
            int rows;                   // Declare the int row as 0 so there is no error there
            printf("Number of rows: "); // Ask for user input how many rows they want to print
            scanf("%d", &rows);         // Scanf the number the user input for the row
            getchar();
            displayData(listData, rows);     // Call the display data with teh listdata array and the number of row
            puts("Press Enter to continue"); // Ask the user to press enter to continue
            getchar();                       // Get the new line
            break;
        case 2:
            // Search function
            // system("cls");
            char searchValue[5005];                    // Declare the searchvalue string
            printf("Choose column: ");                 // Ask user to choose column
            scanf("%s", columnName);                   // Scan for the column name until the new line
            getchar();                                 // Clear the new line
            printf("What data do you want to find? "); // Ask user what data they want to find
            scanf("%s", searchValue);                  // Scan for the search value until newline
            getchar();                                 // Don't forget to clear the newline

            searchByColumn(listData, size, columnName, searchValue); // Call the search by column function with the data previously inputted by user but also the listdata arr and the size of the arr
            puts("Press Enter to continue");                         // Ask the user to press enter to continue
            getchar();                                               // Get the new line
            break;
        case 3:
            // Sort function
            char ascordesc[5005];                                // Declare the string ascordesc
            printf("Choose column: ");                           // print choose column
            scanf("%s", columnName);                             // Input the columns the user want to input
            getchar();                                           // Consume the newline character
            printf("Sort ascending or descending (asc/desc): "); // Ask user is they want to sort the data ascending or descending
            scanf("%s", ascordesc);                              // Get the user input whether ascending or desc
            getchar();                                           // Consume the newline character

            // Perform merge sort
            mergeSort(listData, 0, size - 1, columnName, ascordesc);

            // Display the sorted data
            printf("Sorted data:\n");
            displayData(listData, size);
            puts("Press Enter to continue"); // Ask the user to press enter to continue
            getchar();                       // Get the new line
            break;
        case 4:
            // Export the sorted data to a different file
            printf("Enter the filename to export sorted data: ");
            scanf("%s", exportFilename); // User enter the name of the file they want to use
            // Export sorted data to a new file
            exportToFile(listData, size, exportFilename); // call the export to file function
            puts("Press Enter to continue");              // Ask the user to press enter to continue
            getchar();                                    // Get the new line
            break;
        case 5:
            printf("Exiting...\n"); // Exiting animation
            system("cls");          // Clear screen
            thankYouAnimation();    // The thank you animation
            puts("Thank you");
            break;                  // Don't forget to add break
        default:
            printf("Invalid choice!\n"); // If the input isn't 1 - 5, then print invalid choice
        }
    } while (choice != 5); //Loop while the choice isn't 5

    fclose(f); // Don't forget to close the file again :)

    return 0;
}
