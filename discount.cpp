#include <stdio.h>

int main() {
    double A, B;
    double discountPercentage;

    scanf("%lf %lf", &A, &B);

    if (A >= 1 && A <= 1000000 && B >= 1 && B <= 1000000 && B <= A) {
    	discountPercentage = ((A - B) / A) * 100.0;

    
    	printf("%.2lf%%\n", discountPercentage);
	}
	else {
		printf("Numbers must be between 1 and 1000000, and Y must be greater than or equal to X.\n");
	}

    return 0;
}
