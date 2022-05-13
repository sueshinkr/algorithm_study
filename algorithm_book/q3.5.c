#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int	n, *arr, idx, count, min = INT_MAX;

	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));

	idx = -1;
	while (++idx < n)
	{
		scanf("%d", &arr[idx]);
		count = 0;
		while (arr[idx] % 2 == 0)
		{
			arr[idx] /= 2;
			count++;
		}
		if (count < min)
			min = count;
	}

	printf("%d\n", min);
	free(arr);
	return (0);
}