#include <stdio.h>
#include <string.h>

typedef struct Person
{
    long long int number; // Define a long long integer variable 'number'
    char name[50];        // Define a character array 'name' with size 50

} Lead; // Define a structure 'Lead' with members 'number' and 'name'

Lead arr[1001]; // Declare an array of 'Lead' structures with size 1001

// Function to compare two elements for sorting
int compare(const void *a, const void *b)
{
    struct Person *pa = (struct Person *)a;       // Cast 'a' to a pointer of type 'struct Person'
    struct Person *pb = (struct Person *)b;       // Cast 'b' to a pointer of type 'struct Person'
    long long int diff = pb->number - pa->number; // Calculate the difference between 'number' of 'pb' and 'number' of 'pa'
    if (!diff)                                    // If the difference is zero
        diff = strcmp(pa->name, pb->name);        // Compare the 'name' strings of 'pa' and 'pb'
    return diff;                                  // Return the comparison result
}

int main()
{
    int testCases;           // Declare an integer variable 'testCases'
    scanf("%d", &testCases); // Read an integer from the user and store it in 'testCases'
    getchar();               // Read and discard the newline character

    for (int t = 1; t <= testCases; t++) // Loop 't' from 1 to 'testCases'
    {
        int n;           // Declare an integer variable 'n'
        char name[15];   // Declare a character array 'name' with size 15
        scanf("%d", &n); // Read an integer from the user and store it in 'n'
        getchar();       // Read and discard the newline character

        for (int i = 0; i < n; i++) // Loop 'i' from 0 to 'n-1'
        {
            scanf("%[^#]#%lld", arr[i].name, &arr[i].number); // Read a string followed by '#' and a long long integer, and store them in 'arr[i].name' and 'arr[i].number' respectively
            getchar();                                        // Read and discard the newline character
        }

        for (int i = 0; i < n - 1; i++) // Loop 'i' from 0 to 'n-2'
        {
            for (int j = 0; j < n - i - 1; j++) // Loop 'j' from 0 to 'n-i-2'
            {
                if (compare(&arr[j], &arr[j + 1]) > 0) // If the result of 'compare' function for 'arr[j]' and 'arr[j+1]' is greater than 0
                {
                    struct Person temp = arr[j]; // Create a temporary 'Person' structure and assign 'arr[j]' to it
                    arr[j] = arr[j + 1];         // Assign 'arr[j+1]' to 'arr[j]'
                    arr[j + 1] = temp;           // Assign the temporary structure to 'arr[j+1]'
                }
            }
        }

        scanf("%s", name); // Read a string from the user and store it in 'name'
        getchar();         // Read and discard the newline character

        for (int i = n; i > 0; i--) // Loop 'i' from 'n' to 1
        {
            if (!strcmp(arr[i - 1].name, name)) // If the 'name' string matches 'arr[i-1].name'
            {
                printf("Case #%d: %d\n", t, i); // Print the case number and the value of 'i'
                break;                          // Exit the loop
            }
        }
    }
}