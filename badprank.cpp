#include <stdio.h>
#include <string.h>

char convertCharacter(char arr[])
{
    switch (arr[])
    {
    case '0':
        return 'o';
    case '1':
        return 'I';
    case '3':
        return 'E';
    case '4':
        return 'A';
    case '5':
        return 'S';
    case '6':
        return 'G';
    case '7':
        return 'T';
    case '8':
        return 'B';
    default:
        return arr[];
    }
}

int main()
{
    long long tc;
    long long shift[26];
    char capital[1005];
    long long size;
    FILE *fp = fopen("testdata.in", "r");
    fscanf(fp, "%lld", &tc);
    fgetc(fp);
    for (int i = 0; i < tc; i++)
    {
        fscanf(fp, "%lld", &shift);
        fgetc(fp);
        while (!feof(fp))
        {
            fscanf(fp, "%c", &capital[i]);
            size++;
        }
        convertCharacter(capital);
        fgetc(fp);
        printf("Case #%d: ", i + 1);
        int c[26] = {0};
        int d[26] = {0};
        int j = 0;
        while (X[j] != '\0')
        {
            int z = X[j] - 65;
            d[z]++;
            j++;
            c[j]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (d[i] > 0)
            {
                int shiftAmount = shift[i] % 26;
                char shiftedChar = X[i] - shiftAmount;
                if (shiftedChar < 'A')
                {
                    shiftedChar += 26;
                }
                printf("%c %d\n", shiftedChar, d[i]);
                d[i] = 0;
            }
        }
    }
    fclose(fp);
    return 0;
}

// je ne sais pas