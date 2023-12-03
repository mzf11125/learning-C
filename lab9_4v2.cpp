#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	int tc;
    char a, b;
    int n = 0;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++){
    	scanf("%d %c %c", &n, &a, &b);

    	char str1[100];
    	char str2[100];

    
    	str1[0] = a;
    	str2[0] = b;

    	printf("%s\n", str1);
    	printf("%s", str2);

    	for (int j= 0; j < n; i++)
    	{
        strcat(str1, str2);
        printf("\n%s ", str1);

        strcpy(str2, str1);
        strcat(str2, str2);
        printf("\n%s ", str2);
    	}
    	
	}
    

    return 0;
}
