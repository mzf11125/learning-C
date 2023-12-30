#include <stdio.h>

int main() {
    long long T, N;  // Use long long for test cases and matrix size

    scanf("%lld", &T);  // Read the number of test cases using %lld

    for (long long t = 1; t <= T; t++) {
       scanf("%lld", &N);  // Read the size of the matrices using %lld

       long long matrix1[55][55], matrix2[55][55], matrix3[55][55], result[55][55]; 

       // Read the first matrix using getchar()
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
               matrix1[i][j] = getchar() - '0';  // Convert character to integer
               getchar();  // Consume newline character
           }
       }

       // Read the second matrix using getchar()
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
               matrix2[i][j] = getchar() - '0';
               getchar();
           }
       }

       // Read the third matrix using getchar()
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
               matrix3[i][j] = getchar() - '0';
               getchar();
           }
       }

       // Multiply the matrices
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
               result[i][j] = 0;
               for (int k = 0; k < N; k++) {
                   result[i][j] += matrix1[i][k] * matrix2[k][j] * matrix3[j][k];  // Multiply elements and accumulate
               }
           }
       }

       // Print the result
       printf("Case #%d:\n", t);
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
               printf("%d ", result[i][j]);
           }
           printf("\n");
       }
   }

   return 0;
}
