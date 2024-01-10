#include <stdio.h>
#include <string.h>

struct Player
{
    char name[15];
    int value;
};

int main()
{
    int T, N, i, j, rank;
    char query[15];
    struct Player players[1005];

    scanf("%d", &T);
    for (i = 1; i <= T; ++i)
    {
        scanf("%d", &N);

        // Input player data into the struct array
        for (j = 0; j < N; ++j)
        {
            scanf("%s#%d", players[j].name, &players[j].value);
            getchar();
        }

        scanf("%s", query);
        getchar();

        // Find the index of the player with the specified name
        int queryIndex = 0;
        rank = 1; // Initialize rank to 1
        for (j = 0; j < N; ++j)
        {
            if (strcmp(players[j].name, query) == 0)
            {
                queryIndex = j;
                for (int k = 0; k < N; ++k)
                {
                    if (players[k].value > players[queryIndex].value)
                    {
                        rank++;
                    }
                    else if (players[k].value == players[queryIndex].value && strcmp(players[k].name, query) < 0)
                    {
                        rank++;
                    }
                }
                break;
            }
        }
        printf("Case #%d: %d\n", i, rank);
    }
    return 0;
}
