#include <stdio.h>

//Tips = number that appears the most
//1 1 2 3 4 2 1 1 3
//(123) () () () ()
//int prize[1001] = [][4][2][2][1][][][][][][][][]
// This is the main function where the program execution starts
int main(){
    // Initialize an array of 1001 elements with all elements set to 0
    int prize[1001] = {0}, n, max = 0, temp = 0;

    // Loop through the array and set all elements to 0
    for (int i = 0; i<=1000; i++){
        prize[i] = 0;
    }

    // Read the number of inputs from the user
    scanf("%d", &n);

    // Loop through the inputs and increment the corresponding element in the prize array
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        prize[temp]++;
    }

    // Loop through the prize array and find the element with the highest value
    for (int i = 1; i <= 1000; i++)
    {
        // If the current element has a higher value than the current max, or if it has the same value but a lower index, update the max and maxIndex variables
        if((prize[i]>max)){
            max = prize[i];
        }
    }

    // Print the index of the element with the highest value in the prize array
    printf("%d\n", max);

    // Return 0 to indicate successful program execution
    return 0;
}