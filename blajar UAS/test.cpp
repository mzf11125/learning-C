#include <stdio.h>

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    int arr_neg[105], arr_pos[105];
    int num;
    int size;
    while (!feof(fp))
    {
        fscanf(fp, "%d", "&num");
        {
            if (num < 0)
            {
                arr_neg[size] = num;
                size++;
            } // negative
            else if (num > 0)
            {
                arr_pos[size] = num;
                size++;
            } // positive
        }
    }
    for (int i = 0; i < size; i++)
    {
    }
}