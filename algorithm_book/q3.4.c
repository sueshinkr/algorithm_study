#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ABS(x) x > 0 ? x : (-x) 

int main()
{
	int	n, idx, *arr, min = INT_MAX, max = 0;
	
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));

	idx = -1;
	while (++idx < n)
	{
		scanf("%d", &arr[idx]);
		if (arr[idx] > max)
			max = arr[idx];
		if (arr[idx] < min)
			min = arr[idx];
	}
	
	printf("%d", max - min);
	free(arr);
	return (0);
}