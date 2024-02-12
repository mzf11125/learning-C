//File easy file

#include <stdio.h>

int main() {
	FILE *fp = fopen("testdata.in", "r");
    int negative_min = 0;
    int positive_max = 0;
    int number;

    while (!feof(fp)) {
    	fscanf(fp,"%d", &number);
        if (number < 0) { // negative
            if (negative_min > number) {
                negative_min = number;
            }
        }
        if (number > 0) { // positive
            if (positive_max < number) {
                positive_max = number;
            }
        }
    }
    printf("%d\n", positive_max - negative_min);
    fclose(fp);
    return 0;
}
