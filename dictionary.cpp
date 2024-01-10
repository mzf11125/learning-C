#include <stdio.h>
#include <string.h>

struct Words
{
    char shortAlp[55];    // short abbreviation
    char Alp[55];         // full word
    char arrToPrint[255]; // array to print
};

int linearSearch(Words wordsArray[], int size, char findString[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(wordsArray[i].shortAlp, findString) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    FILE *fp = fopen("testdata.in", "r"); // open input file

    int numOfTestCases;
    fscanf(fp, "%d\n", &numOfTestCases); // read number of test cases

    struct Words wordsArray[105]; // array of Words struct

    for (int i = 0; i < numOfTestCases; i++)
    {
        fscanf(fp, "%[^#]#%[^\n]\n", &wordsArray[i].shortAlp, &wordsArray[i].Alp); // read short abbreviation and full word
    }

    int numOfSentences;
    fscanf(fp, "%d\n", &numOfSentences); // read number of sentences

    for (int i = 0; i < numOfSentences; i++)
    {
        printf("Case #%d:\n", i + 1); // print case number

        char sentence[105];
        fscanf(fp, "%[^\n]\n", &sentence); // read sentence

        char *token = strtok(sentence, " "); // tokenize sentence

        int index = 0;
        while (token != NULL)
        {
            int foundAtIndex = linearSearch(wordsArray, numOfTestCases, token); // search for token in wordsArray

            if (foundAtIndex != -1)
            {
                strcpy(wordsArray[index].arrToPrint, wordsArray[foundAtIndex].Alp); // copy full word to arrToPrint
            }
            else if (foundAtIndex == -1)
            {
                strcpy(wordsArray[index].arrToPrint, token); // copy token to arrToPrint
            }
            index++;
            token = strtok(NULL, " "); // get next token
        }

        for (int j = 0; j < index; j++)
        {
            if (j == index - 1)
            {
                printf("%s\n", wordsArray[j].arrToPrint); // print arrToPrint
            }
            else
            {
                printf("%s ", wordsArray[j].arrToPrint); // print arrToPrint with space
            }
        }
    }

    return 0;
}