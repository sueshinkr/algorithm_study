#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
	int	x;
	int	y;
} cor;

static void swap_cor(int *one, int *two)
{
	int temp_0, temp_1;

	temp_0 = one[0];
	one[0] = two[0];
	two[0] = temp_0;

	temp_1 = one[1];
	one[1] = two[1];
	two[1] = temp_1; 
}

static void	quick_sort(int **cor, int left, int right)
{
	int	low = left + 1, high = right, pivot = left;
	
	if (left < right)
	{
		while (low <= high)
		{	
			while (cor[low][0] <= cor[pivot][0] && low < right)
			{
				if (cor[low][0] == cor[pivot][0] 
					&& cor[low][1] > cor[pivot][1])
					break;
				else
					low++;
			}
			while (cor[high][0] >= cor[pivot][0] && high > left)
			{
				if (cor[high][0] == cor[pivot][0] 
					&& cor[high][1] < cor[pivot][1])
					break;
				else
					high--;
			}
			if (low >= high)
				break;

			swap_cor(cor[low], cor[high]);
			low++;
			high--;
		}
		swap_cor(cor[left], cor[high]);
		quick_sort(cor, left, high - 1);
		quick_sort(cor, low, right);
	}
}

static int compare(const void *a, const void *b)
{
	if (*(int *)a[0] < *(int *)b[0])
		return (-1);
	else if (*(int *)a[0] > *(int *)b[0])
		return (1);
	else
	{
		if (*(int *)a[1] < *(int *)b[1])
			return (-1);
		else if (*(int *)a[1] > *(int *)b[1])
			return (10);
	}
	return (0);
}


int main()
{
	int	num, idx;
	cor *arr_cor;

	scanf("%d", &num);
	cor = (int **)malloc(num * sizeof(int *));
	
	idx = -1;
	while (++idx < num)
	{
		coordinate[idx] = (int *)malloc(2 * sizeof(int));
		scanf("%d %d", &coordinate[idx][0], &coordinate[idx][1]);
	}

	qsort(coordinate, num, sizeof(int *), compare);
	//quick_sort(coordinate, 0, num - 1);

	idx = 0;
	while (idx < num)
	{
		printf("%d %d\n", coordinate[idx][0], coordinate[idx][1]);
		free(coordinate[idx++]);
	}
	free(coordinate);

	return (0);
}
