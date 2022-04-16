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
	int	num, *num_arr, find_num, *find_num_arr;
	int	idx, min, max, mid, lower_ans, upper_ans;

	scanf("%d", &num);
	num_arr = (int *)malloc(num * sizeof(int));
	idx = 0;
	while (idx < num)
		scanf("%d", &num_arr[idx++]);

	scanf("%d", &find_num);
	find_num_arr = (int *)malloc(find_num * sizeof(int));
	idx = 0;
	while (idx < find_num)
		scanf("%d", &find_num_arr[idx++]);

	qsort(num_arr, num, sizeof(int), compare);

	idx = 0;
	while (idx < find_num)
	{
		min = 0;
		max = num - 1;
		lower_ans = -1;
		while (min <= max)
		{
			mid = (min + max) / 2;
			if (find_num_arr[idx] > num_arr[mid])
				min = mid + 1;
			else
			{
				lower_ans = mid;
				max = mid - 1;
			}
		}

		min = 0;
		max = num - 1;
		upper_ans = -1;
		while (min <= max)
		{
			mid = (min + max) / 2;
			if (find_num_arr[idx] < num_arr[mid])
				max = mid - 1;
			else
			{
				upper_ans = mid;
				min = mid + 1;
			}
		}

		if (lower_ans == -1 || upper_ans == -1)
			printf("0");
		else
			printf("%d", upper_ans - lower_ans + 1);
		if (idx != find_num - 1)
			printf(" ");
		idx++;
	}

	free(num_arr);
	free(find_num_arr);
	return (0);
}


