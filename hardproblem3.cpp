#include <stdio.h>
#include <string.h>
int main(){
    int T;
    int number_of_letters;

    scanf("%d", &T);getchar();
    for(int i = 0; i < T; i++){
        scanf("%d", &number_of_letters);getchar();
        int sum = 0;
        char key[101];
        char answer[101];
        scanf("%s", &key); 
        scanf("%s", &answer);
        for(int j = 0; j < number_of_letters; j++){
            if(key[j] == answer[j]){
                sum++;
            }
        }
        int grade = 100*sum/number_of_letters;
        printf("Case #%d: %d\n", i+1, grade);    
    }

    return 0;
}