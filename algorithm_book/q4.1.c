#include <stdio.h>
#include <stdlib.h>

static int	tribo(int n, int *arr)
{
	if (n == 0 || n == 1)
		return (0);
	else if (n == 2)
		return (1);
	else
	{
		if (arr[n] == 0)
			arr[n] = tribo(n - 1, arr) + tribo(n - 2, arr) + tribo(n - 3, arr);
		return (arr[n]);
	}
}

int	main()
{
	int	n, *arr;

	scanf("%d", &n);
	arr = (int *)calloc(n, sizeof(int));

	printf("%d\n", tribo(n, arr));
	free(arr);
	return (0);
}