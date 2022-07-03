#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool partsum(int n, int w, int *arr, int **check)
{
	if (n == 0)
	{
		if (w == 0)
			return (1);
		return (false);
	}
	if (check[n][w] == 1)
		return (1);
	else if (check[n][w] == -1)
		return (0);

	if (partsum(n - 1, w - arr[n - 1], arr, check))
	{
		check[n - 1][w - arr[n - 1]] = 1;
		return (1);
	}
	if (partsum(n - 1, w, arr, check))
	{
		check[n - 1][w] = 1;
		return (1);
	}
	check[n][w] = -1;
	return (false);
}

int main()
{
	int	n, w, idx, *arr;
	int **check;

	scanf("%d %d", &n, &w);
	arr = (int *)malloc(n * sizeof(int));

	idx = -1;
	while (++idx < n)
		scanf("%d", &arr[idx]);

	check = (int **)malloc((n + 1) * sizeof(int *));
	idx = -1;
	while (++idx <=  n)
		check[idx] = (int *)calloc(w + 1, sizeof(int));

	if (partsum(n, w, arr, check))
		printf("true\n");
	else
		printf("false\n");
	return (0);
}