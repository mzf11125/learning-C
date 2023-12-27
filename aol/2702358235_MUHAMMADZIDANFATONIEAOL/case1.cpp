#include <stdio.h>	//Import standart input output library
#include <string.h> //Import string library

int main()
{
	char string[105];		 // Declare string
	scanf("%[^\n]", string); // scanf for string x until new line
	for (int i = 0; i < strlen(string); i++)
	{ // For loop to check the char in the stringays a.k.a the sentence
		if (string[i] >= 'A' && string[i] <= 'Z')
		{					 // if char is greater than or equal to A capital and less than or equal to Z capital then convert it into lowercase
			string[i] += 32; //+32 in ASCII convert lowercase into uppercase
		}
		else if (string[i] >= 'a' && string[i] <= 'z') // If the character is lowercase
		{
			string[i] -= 32; // Make the character capitalize by using -32 in ASCII
		}
	}
	for (int i = strlen(string) - 1; i >= 0; i--) // Print the string in reverse by using decrement from the string length
	{
		printf("%c", string[i]); // Use %c to print the letter one by one
	}
	printf("\n"); // Print new line after printing all the characters in the string
}