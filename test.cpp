#include <stdio.h>

void function(long long N)
{
	int player = 1;

	while (N != 1)
	{
		if (N % 2 == 0) // If N is even
		{
			N = N / 2;			 // Divide N by 2
			player = 1 - player; // Switch player
		}
		else
		{
			N = N * 3 + 1;		 // Multiply N by 3 and add 1
			player = 1 - player; // Switch player
		}
	}
	if (player == 1)	  // If player is 1
		printf("Lili\n"); // Print "Lili"
	else
		printf("Jojo\n"); // Print "Jojo"
}

int main()
{
	int t;
	long long N;
	scanf("%d", &t);			// Read t from input
	for (int i = 0; i < t; i++) // Loop t times
	{
		scanf("%lld", &N);			 // Read N from input
		printf("Case #%d: ", i + 1); // Print "Case #i: "
		function(N);				 // Call function with N
	}
	return 0;
}