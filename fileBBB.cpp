#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[10005];
    FILE *fp = fopen("testdata.in", "r"); // open input file

    int numOfTestCases;
    fscanf(fp, "%d\n", &numOfTestCases); // read number of test case

    int numOfShift;
    fscanf(fp, "%d\n", &numOfShift); // read number of shift

    for (int i = 0; i < numOfTestCases; i++)
    {
        fscanf(fp, "%[^\n]\n", &sentence[i]); // read short abbreviation and full word
        printf("Case #%d:\n", i + 1);         // print case number
        for (int j = 0; j < strlen(sentence); j++)
        {
            // Check each character in strlen
            if (sentence[j] == '0')
            {
                char strtemp = 'O';
                sentence[j] = strtemp;
            }
            else if ()
            {
            }
            else if ()
            {
            }
            else
            {
                printf("%c", sentence[j] - numOfShift);
            }
        }
    }
    {
        for ()
            if (sentence[j] == ' ')
            {
                sprintf(" ");
            }
            else if ()
            {
            }
        {
            printf("%c", sentence[j] + numOfShift);
        }
        else if ()
        {
        }
        else if ()
        {
        }

        else
        {
        }
    }
}

return 0;
}