#include <stdio.h>
#include <string.h>

int main(){
    char string[51];
    scanf("[^\n]");
    int flag = 0;
    int length =strlen(string);
    
    for(int i = 0, j= length-1; i < length, j>=0; i++, j--){
        if(string[i]!=string[j]){
            if(string[i]!=string[j] && string[i]!='_' && string[j]!='_'){//XOR, False if both are true
                flag = 1;
                break;
            }
            else if(string[i] == '_' && string[j] == '_'){//False
                flag = 1;
                break;
            }
            else flag=0;
        }
    }
    if(flag == 1){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }

    return 0;
}