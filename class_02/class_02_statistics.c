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
	int		num, *num_arr, idx, sum = 0, max = -4000, min = 4000;
	int		temp = 1, count = 1, mode, flag = -1;

	scanf("%d", &num);
	num_arr = (int *)malloc(num * sizeof(int));

	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &num_arr[idx]);
		sum += num_arr[idx];
	}

	qsort(num_arr, num, sizeof(int), compare);
	max = num_arr[num - 1];
	min = num_arr[0];
	mode = num == 1 ? num_arr[0] : num_arr[1];

	idx = -1;
	while (++idx + 1 < num)
	{
		if (num_arr[idx] == num_arr[idx + 1])
		{	
			temp++;
			if (temp >= count)
			{	
				if (temp == count && flag == 1)
				{	
					flag = -1;
					mode = num_arr[idx];
				}
				else if (temp > count)
				{
					flag = 1;
					mode = num_arr[idx];
				}
				count = temp;
			}
		}
		else
			temp = 1;
	}
	
	
	if (sum >= 0)
		printf("%d\n", (int)((double)sum / num + 0.5));
	else
		printf("%d\n", (int)((double)sum / num - 0.5));
	printf("%d\n", num_arr[(num - 1) / 2]);
	printf("%d\n", mode);
	printf("%d\n", max - min);

	free(num_arr);
	return (0);
}
