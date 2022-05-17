#include <stdio.h>
#include <stdlib.h>

static int	compare(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	return (0);
}

int	main()
{
	int	num, *arr, idx, sum = 0;

	scanf("%d", &num);
	arr = (int *)malloc(num * sizeof(int));

	idx = -1;
	while (++idx < num)
		scanf("%d", &arr[idx]);
		
	qsort(arr, num, sizeof(int), compare);

	idx = -1;
	while (++idx < num)
		sum += arr[idx] * (num - idx);

	printf("%d", sum);
	free(arr);
	return (0);
}