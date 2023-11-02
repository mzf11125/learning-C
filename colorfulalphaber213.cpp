#include <stdio.h>
#include <string.h>

void word(int number){
    
    char word = 'a';
    for (int i = 0; i < number; i++)
    {
        printf("%c", word);
        word++;

    }   
}

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int number;
        scanf("%d", &number);
        printf("Case #%d: ", i+1);   
        word(number);
        printf("\n");
    }


    return 0;
}