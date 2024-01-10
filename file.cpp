#include <stdio.h>
#include <string.h>


int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

char *trim(char *str) {
    char *end;
    while(is_space(*str)) str++;
    if(*str == 0) return str;
    end = str + strlen(str) - 1;
    while(end > str && is_space(*end)) end--;
    end[1] = '\0';
    return str;
}

int main() {
    FILE *file = fopen("testadatest.txt", "r");
    if (file == NULL) {
        printf("Could not open file testdata.in\n");
        return 1;
    }
    int T, TC, i, j;
    char dictionary[105][2][50], sentence[105], *word;
    fscanf(file, "%d", &T);
    for(i = 0; i < T; i++) {
        fscanf(file, "%[^#]#%[^\n]\n", dictionary[i][0], dictionary[i][1]);
        strcpy(dictionary[i][0], trim(dictionary[i][0]));
        strcpy(dictionary[i][1], trim(dictionary[i][1]));
    }
    fscanf(file, "%d", &TC);
    fgetc(file); // To consume newline character after fscanf
    for(i = 0; i < TC; i++) {
        fgets(sentence, sizeof(sentence), file);
        printf("Case #%d:\n", i+1);
        word = strtok(sentence, " \n");
        while(word != NULL) {
            for(j = 0; j < T; j++) {
                if(strcmp(word, dictionary[j][0]) == 0) {
                    printf("%s ", dictionary[j][1]);
                    break;
                }
            }
            if(j == T) {
                printf("%s ", word);
            }
            word = strtok(NULL, " \n");
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}
