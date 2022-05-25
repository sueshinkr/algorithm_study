#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
	int one = *(int *)a;
	int two = *(int *)b;

	if (one < two)
		return (-1);
	else if (one > two)
		return (1);
	return (0);
}

static void	search(int *sort_arr, int find_num, int new_idx)
{
	int	min = 0, max = new_idx, mid;

	while (min <= max)
	{
		mid = (min + max) / 2;
		if (find_num > sort_arr[mid])
			min = mid + 1;
		else if (find_num < sort_arr[mid])
			max = mid;
		else
			break;
	}
	printf("%d", mid);
}

int	main()
{
	int	n, idx = -1, new_idx = 1;
	int	*arr, *sort_arr;
	
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	sort_arr = (int *)malloc(n * sizeof(int));

	while (++idx < n)
	{
		scanf("%d", &arr[idx]);
		sort_arr[idx] = arr[idx];
	}

	qsort(sort_arr, n, sizeof(int), compare);

	idx = 0;
	while (++idx < n)
	{
		if (sort_arr[idx] == sort_arr[idx - 1])
			;
		else
			sort_arr[new_idx++] = sort_arr[idx];
	}

	idx = -1;
	while(++idx < n)
	{
		search(sort_arr, arr[idx], new_idx - 1);
		if (idx != n - 1)
			printf(" ");
	}

	free(arr);
	free(sort_arr);
	return (0);
}
