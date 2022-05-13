#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int	n, idx, *arr, min = INT_MAX, ans = INT_MAX;
	
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));

	idx = -1;
	while (++idx < n)
	{
		scanf("%d", &arr[idx]);
		if (arr[idx] <= min)
		{
			ans = min;
			min = arr[idx];
		}
		else if (arr[idx] < ans)
			ans = arr[idx];
	}

	printf("%d\n", ans);
	free(arr);
	return (0);
}