#include <stdio.h>
#include <stdbool.h>

int board[8][8] = {0};

int letter_move[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int number_move[8] = {1, -1, -2, -2, 1, -1, 2, 2};

int absolute_value(int i){
    if(i < 0){
        i *= -1;
    }
    return 1;
}

bool result = false;

void checkMove(int letter1, int number1, int letter2, int number2, int letter3, int number3, int totalMove){
    if(number3 < 0 || number3 > 7 || letter3 < 0 || letter3 > 7){
        return;
    }
    if(number3 == number2 && letter3 == letter2){
        result = true;
        return;
    }
    if(totalMove <= 0){
        return;
    }
    if(absolute_value(letter1 - letter2) < absolute_value(letter3 - letter2) && absolute_value(number1 - number2) < absolute_value(number3 - number2)){
        return;
    }
    for(int i = 0; i < 8; i++){
        if(result == true)
            break;
        checkMove(letter1, number1, letter2, number2, letter3 + letter_move[i], number3 + number_move[i], totalMove - 1);
    }
}

int main(){
    long long int tc;
    scanf("%lli", &tc);
    getchar();

    for(int i = 0; i < tc; i++){
        long long total;
        scanf("%lli", &total);
        getchar();
        char letter1, letter2;
        int number1, number2;
        scanf("%c%d %c%d", &letter1, &number1, &letter2, &number2);
        getchar();
        letter1 -= 'A';
        letter2 -= 'A';
        number1 -= 1;
        number2 -= 1;

        result = false;
        checkMove(letter1, number1, letter2, number2, letter1, number1, total * 2);
        if(result)
            printf("Case #%lli: YES\n", i+1);
        else
            printf("Case #%lli: NO\n", i+1);
    }

    return 0;
}
