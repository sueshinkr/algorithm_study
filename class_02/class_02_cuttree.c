#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return (-1);
	else if (*(int *)a > *(int *)b)
		return (1);
	return (0);
}

int main()
{
	int			num, *num_arr, idx = 0, cut, min, max, result;
	long long	sum, target;

	scanf("%d %lld", &num, &target);
	num_arr = (int *)malloc(num * sizeof(int));
	
	while (idx < num)
		scanf("%d", &num_arr[idx++]);

	qsort(num_arr, num, sizeof(int), compare);

	min = 0;
	max = num_arr[num - 1];

	while (min <= max)
	{
		cut = (min + max) / 2;
		sum = 0;
		idx = 0;
		while (idx < num)
		{ 	
			if (num_arr[idx] - cut >= 0)
				sum += num_arr[idx] - cut;
			idx++;
		}
		if (sum < target)
			max = cut - 1;
		else if (sum >= target)
		{	
			result = cut;
			min = cut + 1;
		}
	}
	printf("%d", result);
	free(num_arr);
	return (0);
}
