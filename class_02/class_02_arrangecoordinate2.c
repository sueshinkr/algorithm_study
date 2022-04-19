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
	
	if (a.y < b.y)
		return (-1);
	else if (a.y > b.y)
		return (1);
	else
	{
		if (a.x > b.x)
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
