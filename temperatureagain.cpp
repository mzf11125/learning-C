#include <stdio.h>
#include <string.h>

struct City
{
    char name[1005];
    double temperature;
    char metric;
} cities[10005];

void merge(struct City cities[], int left, int mid, int right)
{
    struct City temp[105];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (cities[i].temperature < cities[j].temperature)
        {
            temp[k++] = cities[i++];
        }
        else if (cities[i].temperature > cities[j].temperature)
        {
            temp[k++] = cities[j++];
        }
        else
        {
            // If temperatures are equal, sort by city name in ascending order
            if (strcmp(cities[i].name, cities[j].name) <= 0)
            {
                temp[k++] = cities[i++];
            }
            else
            {
                temp[k++] = cities[j++];
            }
        }
    }

    while (i <= mid)
    {
        temp[k++] = cities[i++];
    }

    while (j <= right)
    {
        temp[k++] = cities[j++];
    }

    for (int i = left, k = 0; i <= right; i++, k++)
    {
        cities[i] = temp[k];
    }
}

void mergeSort(struct City cities[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(cities, left, mid);
    mergeSort(cities, mid + 1, right);
    merge(cities, left, mid, right);
}

int main()
{
    int n = 0;

    FILE *cp = fopen("temperaturetest.txt", "r");
    if (cp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(cp, "%[^#]#%lf#%c\n", cities[n].name, &cities[n].temperature, &cities[n].metric) != EOF)
    {
        n++;
    }

    fclose(cp);

    // Create a temporary array for converting temperatures to Celsius
    struct City tempCities[10005];
    for (int i = 0; i < n; i++)
    {
        tempCities[i] = cities[i];
        if (cities[i].metric == 'F')
        {
            tempCities[i].temperature = (tempCities[i].temperature - 32) * 5 / 9;
            tempCities[i].metric = 'C';
        }
    }

    // Sort the temporary array
    mergeSort(tempCities, 0, n - 1);

    // Print the sorted temperatures from the original array
    for (int i = 0; i < n; i++)
    {
        printf("%s is %.2lf%c\n", tempcities[i].name, tempCities[i].temperature, tempCities[i].metric);
    }

    return 0;
}
