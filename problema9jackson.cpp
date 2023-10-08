#include <stdio.h>

int main()
{
    int T, Y = 0;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int X;
        scanf("%d", &X);
        Y += X;
        if(Y==12){
            Y=28;
        }
        else if(Y==30){
            Y=10;
        }
        else if(Y==35){
            Y=7;
        }
        if(Y>=40){
            Y -= 40;//Should be minus 40, not 41. Use the -= sign
        }
    }
    printf("%d\n", Y);

    return 0;
}
