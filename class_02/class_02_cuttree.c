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
	int	num, target, *num_arr, idx = 0;
	int	min, max, cut, temp, cmp = 0;

	scanf("%d %d", &num, &target);
	num_arr = (int *)malloc(num * sizeof(int));
	
	while (idx < num)
		scanf("%d", &num_arr[idx++]);

	qsort(num_arr, num, sizeof(int), compare);

	min = num_arr[0];
	max = num_arr[num - 1];
	cut = (min + max) / 2;

	while (1)
	{
		temp = 0;
		while (idx < num)
			temp += num_arr[idx++] - cut;
		if (temp < target)
		{
			printf("cut : %d, temp : %d\n", cut, temp);
			max = cut;
			cut = (cut + min) / 2;
		}
		else if (temp >= target)
		{
			printf("cut : %d, temp : %d\n", cut, temp);
			if (temp > cmp)
				cmp = temp;
			else
				break;
			min = cut;
			cut = (cut + max) / 2;
		}
	}
	printf("%d", cut);
	free(num_arr);
	return (0);
}
