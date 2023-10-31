#include <stdio.h>
#include <string.h>
// Special palindrome

int main(){

    char string[101];
    char underscore = '_';
    int length = strlen(string);
    scanf("%[^\n]", string); getchar();

    if(length > 0 && length < 101){
        for(int i = 0; i < length; i++){
            if(string[i] == underscore){
                string[i] = string[i + 1];
            }
        }
    }
    printf("Yes\n");
    }
    else if (*result != NULL && *result == underscore){
    printf("No\n");
    }
    else{
    printf("Yes\n");
    }

    return 0;
}