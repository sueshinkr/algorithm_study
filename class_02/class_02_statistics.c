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
	int		num, idx = 0, max = -4000, min = 4000;
	int		temp = 1, count = 1, mode, flag = -1;
	int		*num_arr;
	double	sum = 0.0;

	scanf("%d", &num);
	num_arr = (int *)malloc(num * sizeof(int));

	while (idx < num)
	{
		scanf("%d", &num_arr[idx]);
		sum += num_arr[idx++];
	}

	qsort(num_arr, num, sizeof(int), compare);
	
	max = num_arr[num - 1];
	min = num_arr[0];
	mode = num_arr[0];

	idx = -1;
	while (++idx < num)
	{
		if (mode < num_arr[idx])
		{
			mode = num_arr[idx];
			break;
		}
	}

	idx = 0;
	while (idx + 1 < num)
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
		idx++;
	}
	
	/*
	if (sum >= 0)
		printf("%d\n", (int)((sum / num) + 0.5));
	else
		printf("%d\n", (int)((sum / num) - 0.5));
	*/
	printf("%.0f\n", sum / num);
	printf("%d\n", num_arr[(num - 1) / 2]);
	printf("%d\n", mode);
	printf("%d\n", max - min);

	return (0);
}
