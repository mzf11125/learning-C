#include <stdio.h>
#include <string.h>

struct data
{
    int number;
    char name[105];
} datalist[1005];

void merge(struct arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        int
    }
}

void mergeSort()
{
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        scanf("%d %s", &datalist[i].number, datalist[i].name);
        getchar();
    }
    
    mergeSort()
    // for (int i = 0; i < t; i++)
    // {
    //     printf("%d %s", datalist[i].number, datalist[i].name);
    // }

    return 0;
}