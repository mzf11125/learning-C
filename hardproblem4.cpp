#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++) {
        int number_of_letters;
        scanf("%d", &number_of_letters);
        // getchar();
        int grade = 100 / number_of_letters;

        char key[101];
        char answer[101];

        for (int j = 0; j < number_of_letters; j++) {
            scanf("%c", &key[j]);
        }
        // getchar();

        for (int j = 0; j < number_of_letters; j++) {
            scanf("%c", &answer[j]);
        }

        int equal = 1; // Variable to check if the answer is the same as the key

        for (int j = 0; j < number_of_letters; j++) {
            if (answer[j] != key[j]) {
                equal = 0; // Set equal to 0 if any character doesn't match
                break;
            }
            int total_grade = graded;
        }

        if (equal) {
            
        } else {
            // Handle the case when the answer is not the same as the key
        }
    }

    return 0;
}
