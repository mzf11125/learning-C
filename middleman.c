#include <stdio.h>

int main()
{
    int num1, num2, num3;
    
    scanf("%d", &num1);getchar();
    scanf("%d", &num2);getchar();
    scanf("%d", &num3);
    
    int middleDigit1 = (num1 / 10) % 10;
    int middleDigit2 = (num2 / 10) % 10;
    int middleDigit3 = (num3 / 10) % 10;
    
    printf("%d\n%d\n%d\n", middleDigit1, middleDigit2, middleDigit3);

    return 0;
}
