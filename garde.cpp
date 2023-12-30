#include <stdio.h>

int main() {
   long long X, Y, T;

   // Read garden dimensions
   scanf("%lld %lld", &X, &Y);

   // Declare the garden array
   long long garden[X][Y];

   // Read initial garden state
   for (int i = 0; i < X; i++) {
       for (int j = 0; j < Y; j++) {
           scanf("%lld", &garden[i][j]);
       }
       getchar();
   }

   // Read number of changes
   scanf("%lld", &T);

   // Process changes
   for (int i = 0; i < T; i++) {
       long long a, b, c;
       scanf("%lld %lld %lld", &a, &b, &c);getchar();

       // Adjust for 0-based indexing
       a--;
       b--;

       // Apply the change
       garden[a][b] = c;
   }

   // Print the updated garden
   for (int i = 0; i < X; i++) {
       for (int j = 0; j < Y; j++) {
           printf("%lld ", garden[i][j]);
       }
       printf("\n");
   }

   return 0;
}
