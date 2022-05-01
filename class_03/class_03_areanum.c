#include <stdio.h>
#include <stdlib.h>

static int	compare(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

static void	check(int **map, int size, int column, int row, int count)
{
	if (row < size - 1 && map[column][row + 1] == 1)
	{
		map[column][row + 1] += count;
		check(map, size, column, row + 1, count);
	}
	if (column < size - 1 && map[column + 1][row] == 1)
	{
		map[column + 1][row] += count;
		check(map, size, column + 1, row, count);
	}
	if (row > 0 && map[column][row - 1] == 1)
	{
		map[column][row - 1] += count;
		check(map, size, column, row - 1, count);
	}
	if (column > 0 && map[column - 1][row] == 1)
	{
		map[column - 1][row] += count;
		check(map, size, column - 1, row, count);
	}
}

int main()
{
	int	size, **map, column, row, *areanum, count = 0, idx;
	char	temp_map[25];

	scanf("%d", &size);
	map = (int **)malloc(size * sizeof(int *));

	column = -1;
	while (++column < size)
	{
		scanf("%s", temp_map);
		map[column] = (int *)malloc(size * sizeof(int));
		row = -1;
		while (++row < size)
			map[column][row] = temp_map[row] - '0';
	}

	column = -1;
	while (++column < size)
	{
		row = -1;
		while (++row < size)
		{
			if (map[column][row] == 1)
			{
				count++;
				map[column][row] += count;
				check(map, size, column, row, count);
			}
		}
	}

	areanum = (int *)calloc(count + 1, sizeof(int));
	column = -1;
	while (++column < size)
	{
		row = -1;
		while (++row < size)
		{
			if (map[column][row] > 1)
				areanum[map[column][row] - 2]++;
		}
	}
	qsort(areanum, count, sizeof(int), compare);

	printf("%d\n", count);
	idx = -1;
	while (++idx < count)
		printf("%d\n", areanum[idx]);

	
	free(areanum);
	idx = -1;
	while (++idx < column)
		free(map[idx]);
	free(map);
	
	return (0);
}
