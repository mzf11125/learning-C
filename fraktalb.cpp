// #include <stdio.h>

// int fraktal_B(int x)
// {
// 	int i;
// 	if (x <= 0)
// 	{
// 		return 0;
// 	}
// 	else
// 	{
// 		int bintang = x;
// 		bintang += fraktal_B(x - 1); // call again x-1
// 		// for (i = 1; i <= x; i++) printf("*");//print bintang
// 		bintang += fraktal_B(x - 2); //
// 		return bintang;
// 	}
// }

// int main()
// {
// 	int x;
// 	scanf("%d", &x);
// 	getchar();
// 	int result = fraktal_B(x);
// 	printf("%d\n", result);
// }

// #include <stdio.h>

// // const int MAX = ;
// int memo[1000]; // Memory to store the results of fraktal_B function

// int fraktal_B(int x)
// {
// 	if (x <= 0)
// 	{
// 		return 0;
// 	}

// 	if (memo[x] != 0) // If the result for x is already calculated and stored in memory
// 	{
// 		return memo[x]; // Return the stored result
// 	}

// 	int bintang = x;
// 	bintang += fraktal_B(x - 1); // Recursively call fraktal_B with x-1
// 	bintang += fraktal_B(x - 2); // Recursively call fraktal_B with x-2

// 	memo[x] = bintang; // Store the result in memory to avoid redundant calculations
// 	return bintang;
// 	// if (x <= 0)
// 	// {
// 	// 	return 0;
// 	// }

// 	// int memo[x + 1];
// 	// memo[0] = 0;
// 	// memo[1] = 1;

// 	// for (int i = 2; i <= x; ++i)
// 	// {
// 	// 	memo[i] = i + memo[i - 1] + memo[i - 2];
// 	// }

// 	// return memo[x];
// }

// int main()
// {
// 	int x;
// 	scanf("%d", &x);
// 	getchar();
// 	int result = fraktal_B(x);
// 	printf("%d\n", result);
// }

#include <stdio.h>

const int MAX = 100000;
long long memo[MAX + 1]; // Use long long for larger values

long long fraktal_B_dynamic(long long x)
{
	if (x <= 0)
	{
		return 0;
	}

	memo[0] = 0;
	memo[1] = 1;

	for (int i = 2; i <= x; ++i)
	{
		memo[i] = (long long)i + memo[i - 1] + memo[i - 2];
	}

	return memo[x];
}

int main()
{
	long long x;
	scanf("%lld", &x);
	getchar();

	long long result = fraktal_B_dynamic(x);
	printf("%lld\n", result);

	return 0;
}
