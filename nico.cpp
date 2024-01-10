#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        int N;
        scanf("%d", &N);

        char nama[N][12];
        int nilai[N];
        char target[12];
        int result = -1;

        for (int i = 0; i < N; i++)
        {
            scanf("%[^#]#%d", nama[i], &nilai[i]);
            getchar();
        }

        // Bubble sort to sort nilai array in descending order
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - i - 1; j++)
            {
                if (nilai[j] < nilai[j + 1])
                {
                    // Swap values
                    int tempNilai = nilai[j];
                    nilai[j] = nilai[j + 1];
                    nilai[j + 1] = tempNilai;

                    // Swap names
                    char tempNama[12];
                    strcpy(tempNama, nama[j]);
                    strcpy(nama[j], nama[j + 1]);
                    strcpy(nama[j + 1], tempNama);
                }
            }
        }

        scanf("%s", target);

        for (int i = 0; i < N; i++)
        {
            if (strcmp(target, nama[i]) == 0)
            {
                result = i + 1;
                break;
            }
        }

        printf("Case #%d: %d\n", t, result);
    }

    return 0;
}