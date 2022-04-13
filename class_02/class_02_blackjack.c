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
	int	card1, card2, card3, temp, result = 0;

	scanf("%d %d", &num, &target);
	num_arr = (int *)malloc(num * sizeof(int));

	while (idx < num)
		scanf("%d", &num_arr[idx++]);
	
	qsort(num_arr, num, sizeof(int), compare);

	card1 = -1;
	while (card1++ < num)
	{
		card2 = card1;
		while (card2++ < num)
		{
			if (num_arr[card1] + num_arr[card2] > target)
				break;
			card3 = card2;
			while (card3++ < num)
			{
				temp = num_arr[card1] + num_arr[card2] + num_arr[card3];
				if (temp > target)
					break;
				else if (temp > result)
					result = temp;
			}
		}
	}
	printf("%d", result);
	free(num_arr);
	return (0);
}
