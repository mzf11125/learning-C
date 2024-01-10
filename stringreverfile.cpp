#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;
    FILE *ptr;
    char ch[1001];
    int size = 0, sizes = 0, alphabet;
    ptr = fopen("testdata.in", "r");
//	ptr = fopen("testdates1.txt", "r");

    fscanf(ptr, "%d\n", &n);

    while (size < n)
    {
        fscanf(ptr, "%d\n", &alphabet);
        fscanf(ptr, "%[^\n]\n", ch);
        size++;
        printf("Case #%d: ", size);

        int len = strlen(ch); // Store the length of the string

        for (int i = 0; i < len; i++)
        {
            char def = ch[i]; //Lebih gampang dibaca

//            // Lookup table for character conversion
//            static const char conversionTable[] = {
//                ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
//                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

			if(def == '0'){
				def = 'O';
			}
			else if(def == '1'){
				def = 'I';
			}
			else if(def == '3'){
				def = 'E';
			}
			else if(def == '4'){
				def = 'A';
			}
			else if(def == '5'){
				def = 'S';
			}
			else if(def == '6'){
				def = 'G';
			}
			else if(def == '7'){
				def = 'T';
			}
			else if(def == '8'){
				def = 'B';
			}
//            // Convert characters based on the given rules
//            if (def >= '0' && def <= '8')
//            {
//                def = conversionTable[def - '0'];
//                def -= alphabet;
//            }
            
            
            if(def != ' '){
				def -= alphabet;
			}
        

            // Handle wraparound for characters outside the range of 'A' to 'Z', make sure the range is not outside alphabet
            if (def < 'A' && def != ' ')
            {
                def = 'Z' - ('A' - def) + 1;
                
//				def = +
//                 90 - (65-1) + 1
            }

            printf("%c", def);
        }
        puts("");
    }
}