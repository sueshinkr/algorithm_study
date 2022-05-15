#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	num;
int	**arr;
bool **line;

static void	dfs(int top, int row)
{
	int	column = -1;

	while (++column < num)
	{
		if (arr[row][column] && !line[top][column])
		{
			line[top][column] = true;
			dfs(top, column);
		}
	}
}

int	main()
{
	int	row, column;

	scanf("%d", &num);
	arr = (int **)malloc(num * sizeof(int *));
	line = (bool **)malloc(num * sizeof(bool *));

	row = -1;
	while (++row < num)
	{
		arr[row] = (int *)malloc(num * sizeof(int));
		line[row] = (bool *)calloc(num, sizeof(bool));
		column = -1;
		while (++column < num)
			scanf("%d", &arr[row][column]);
	}

	row = -1;
	while (++row < num)
		dfs(row, row);

	row = -1;
	while (++row < num)
	{
		column = -1;
		while (++column < num)
		{
			if (column != num - 1)
				printf("%d ", line[row][column]);
			else
				printf("%d\n", line[row][column]);
		}
		free(arr[row]);
		free(line[row]);
	}
	free(arr);
	free(line);
	return (0);
}

/*

int	**arr;

int	main()
{
	int	num, row, column;

	scanf("%d", &num);
	arr = (int **)malloc(num * sizeof(int *));

	row = -1;
	while (++row < num)
	{
		arr[row] = (int *)malloc(num * sizeof(int));
		column = -1;
		while (++column < num)
			scanf("%d", &arr[row][column]);
	}
*/