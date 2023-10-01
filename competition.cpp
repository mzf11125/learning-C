#include <stdio.h>

int main() {
    int A[4], B[4];
    


	for (int i = 0; i < 4; i++){
		scanf("%d %d", &A[i], &B[i]);
		getchar();
	}
	for (int i = 0; i < 4; i++){
		int multiply = A[i] * B[i];
		printf("%d\n", multiply);
	}

    return 0;
}
