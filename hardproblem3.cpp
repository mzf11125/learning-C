#include <stdio.h>
#include <string.h>
int main(){
    int T;
    int number_of_letters;

    scanf("%d", &T);getchar();
    for(int i = 0; i < T; i++){
        scanf("%d", &number_of_letters);getchar();
        int grade = 100/number_of_letters;
        char key[101];
        char answer[101];
        for (int j = 0; j < number_of_letters; j++){
            scanf("%c ", &key[j]); 
        }
        getchar();
        for (int j = 0; j < number_of_letters; i++)
        {
            scanf(" %c ", &answer[j]);
        }
        
        int equal = 1;

        for(int j = 0; j < number_of_letters; j++){
            if(key[j] != answer[j]){
                equal = 0;
                break;
            }
        }

        printf("%d\n", grade);
        printf("\n");
    
    }

    return 0;
}