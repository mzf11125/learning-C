#include <stdio.h>
#include <string.h>

typedef struct {
 char short_word[50];
 char original_word[50];
} DictionaryEntry;

DictionaryEntry dictionary[100];
int dictionary_size;

int get_line(char *buffer, int size) {
 int ch, i;
 for (i = 0; (ch = getchar()) != EOF && ch != '\n' && i < size - 1; i++) {
    buffer[i] = ch;
 }
 buffer[i] = '\0';
 return i + (ch == '\n');
}

int read_dictionary(char *filename) {
 FILE *file = fopen(filename, "r");
 if (!file) {
    printf("Error opening dictionary file!\n");
    return -1;
 }

 fscanf(file, "%d", &dictionary_size);
 for (int i = 0; i < dictionary_size; i++) {
    fscanf(file, "%s#%s", dictionary[i].short_word, dictionary[i].original_word);
 }
 fclose(file);
 return dictionary_size;
}

char *translate_sentence(char *sentence) {
 static char translated_sentence[1000];
 char *src = sentence, *dst = translated_sentence;
 int i, j, found;

 while (*src) {
    if (*src == ' ') {
      *dst++ = *src++;
      continue;
    }

    found = 0;
    for (j = 0; j < dictionary_size; j++) {
      if (strncmp(src, dictionary[j].short_word, strlen(dictionary[j].short_word)) == 0) {
        found = 1;
        strcpy(dst, dictionary[j].original_word);
        dst += strlen(dictionary[j].original_word);
        src += strlen(dictionary[j].short_word);
        break;
      }
    }

    if (!found) {
      *dst++ = *src++;
    }
 }

 *dst = '\0';
 return translated_sentence;
}

int main(void) {
 int num_cases, i;
 char sentence[1000];
 char filename[] = "testdata34.txt";

 if (read_dictionary(filename) < 0) {
    return 1;
 }

 FILE *file = fopen(filename, "r");
 if (!file) {
    printf("Error opening dictionary file!\n");
    return 1;
 }

 if (fscanf(file, "%d", &num_cases) != 1) {
    printf("Error reading number of test cases!\n");
    return 1;
 }

 for (i = 1; i <= num_cases; i++) {
    if (get_line(sentence, sizeof(sentence)) <= 0) {
      printf("Error reading sentence!\n");
      return 1;
    }
   
    printf("Case #%d: %s\n", i, translate_sentence(sentence));
 }

 fclose(file);
 return 0;
}