#include <stdio.h>
#include <string.h>

struct data
{
	char s[1000];
	int vowel; // track jumlah vowel atau vokal
};

data arr[101];

int countVowel(char *s)
{
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
		{
			count++;
		}
	}
	return count;
}

void sort(int left, int mid, int right)
{
	int l1 = mid - left + 1;
	int r1 = right - mid;

	data L[l1 + 1];
	data R[r1 + 1];

	for (int i = 0; i < l1; i++)
	{
		L[i] = arr[i + left];
	}

	for (int i = 0; i < r1; i++)
	{
		R[i] = arr[mid + 1 + i];
	}
	int i, j, k;
	i = j = 0;
	k = left;

	while (i < l1 && j < r1)
	{
		if (L[i].vowel > R[j].vowel)
		{
			arr[k] = L[i];
			i++;
		}
		else if (L[i].vowel == R[j].vowel)
		{
			if (strcmp(L[i].s, R[j].s) < 0)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < l1)
	{
		arr[k] = L[i];
		i++, k++;
	}
	while (j < r1)
	{
		arr[k] = R[j];
		j++, k++;
	}
}

void merge(int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2; // ini
		merge(left, mid);
		merge(mid + 1, right);
		sort(left, mid, right);
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	getchar();

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr[i].s);
		arr[i].vowel = countVowel(arr[i].s);
		getchar();
	}
	merge(0, N - 1);
	// debug
	printf("Output:\n");
	for (int i = 0; i < N; i++)
	{
		printf("%s\n", arr[i].s);
	}
	return 0;
}