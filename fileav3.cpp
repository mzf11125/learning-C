#include <stdio.h>
#include <string.h>

typedef struct {
    char key[50];
    char value[50];
} Dictionary;

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
    Dictionary dictionary[105];
    char sentence[105], *word, result[105] = "";
    fscanf(file, "%d", &T);
    for(i = 0; i < T; i++) {
        fscanf(file, "%[^#]#%[^\n]\n", dictionary[i].key, dictionary[i].value);
        strcpy(dictionary[i].key, trim(dictionary[i].key));
        strcpy(dictionary[i].value, trim(dictionary[i].value));
    }
    fscanf(file, "%d", &TC);
    fgetc(file); // To consume newline character after fscanf
    for(i = 0; i < TC; i++) {
        fgets(sentence, sizeof(sentence), file);
        printf("Case #%d: ", i+1);
        word = strtok(sentence, " \n");
        while(word != NULL) {
            for(j = 0; j < T; j++) {
                if(strcmp(word, dictionary[j].key) == 0) {
                    strcat(result, dictionary[j].value);
                    strcat(result, " ");
                    break;
                }
            }
            if(j == T) {
                strcat(result, word);
                strcat(result, " ");
            }
            word = strtok(NULL, " \n");
        }
        printf("%s\n", result);
        strcpy(result, "");
    }
    fclose(file);
    return 0;
}
