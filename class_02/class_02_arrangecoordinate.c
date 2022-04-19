#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
	int	x;
	int	y;
} cor;

static int compare(const void *one, const void *two)
{
	cor	a = *(cor *)one;
	cor	b = *(cor *)two;
	
	if (a.x < b.x)
		return (-1);
	else if (a.x > b.x)
		return (1);
	else
	{
		if (a.y > b.y)
			return (1);
		else
			return (-1);
	}
	return (0);
}

int main()
{
	int	num, idx;
	cor *xy;

	scanf("%d", &num);
	xy = (cor *)malloc(num * sizeof(cor));
	
	idx = -1;
	while (++idx < num)
		scanf("%d %d", &xy[idx].x, &xy[idx].y);

	qsort(xy, num, sizeof(cor), compare);
	//quick_sort(xy, 0, num - 1);

	idx = -1;
	while (++idx < num)
		printf("%d %d\n", xy[idx].x, xy[idx].y);
	
	free(xy);
	return (0);
}


/*
static void swap_cor(cor **xy, int a, int b)
{
	cor *temp;

	temp = xy[a];
	xy[a] = xy[b];
	xy[b] = temp;
}

static void	quick_sort(cor **xy, int left, int right)
{
	int	low = left + 1, high = right, pivot = left;
	
	if (left < right)
	{
		while (low <= high)
		{	
			while (xy[low]->x <= xy[pivot]->x && low < right)
			{
				if (xy[low]->x == xy[pivot]->x 
					&& xy[low]->y > xy[pivot]->y)
					break;
				else
					low++;
			}
			while (xy[high]->x >= xy[pivot]->x && high > left)
			{
				if (xy[high]->x == xy[pivot]->x 
					&& xy[high]->y < xy[pivot]->y)
					break;
				else
					high--;
			}
			if (low >= high)
				break;

			swap_cor(xy, low, high);
			low++;
			high--;
		}
		swap_cor(xy, left, high);
		quick_sort(xy, left, high - 1);
		quick_sort(xy, low, right);
	}
}
*/
