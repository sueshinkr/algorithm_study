#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num, idx, rank, temp;
	int	*height, *weight;
	
	scanf("%d", &num);
	height = (int *)malloc(num * sizeof(int));
	weight = (int *)malloc(num * sizeof(int));

	idx = -1;
	while (++idx < num)
		scanf("%d %d", &height[idx], &weight[idx]);
	
	idx = -1;
	while (++idx < num)
	{
		if (idx != 0)
			printf(" ");

		rank = 1;
		temp = -1;
		while (++temp < num)
		{
			if (height[idx] < height[temp] 
				&& weight[idx] < weight[temp])
				rank++;
		}
		printf("%d", rank);
	}

	free(height);
	free(weight);
	return (0);
}
