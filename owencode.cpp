#include <stdio.h>
#include <string.h>

struct Kata {
    char singkatan[51];
    char OG[51];
    char sentence[101];
};

int main() {
    FILE *fp = fopen("testadatest.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open the file.\n");
        return 1;  // Exit with an error code
    }

    int T;
    fscanf(fp, "%d\n", &T);

    struct Kata kata[101];  // Array of structures

    for (int i = 0; i < T; i++) {
        fscanf(fp, "%[^#]#%[^\n]\n", kata[i].singkatan, kata[i].OG);
    }

    int X;
    fscanf(fp, "%d\n", &X);

    for (int i = 0; i < X; i++) {
        fgets(kata[i].sentence, 101, fp);
        printf("\bCase #%d:\n",i+1);

        char *token = strtok(kata[i].sentence, " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < T; j++) {
                if (strcmp(token, kata[j].singkatan) == 0) {
                    printf("%s ", kata[j].OG);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}