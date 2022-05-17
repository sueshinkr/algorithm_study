#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char	**arr;
bool	**check;

static void	is_same(int num, int row, int column)
{
	char	cur = arr[row][column];

	if (row < num - 1 && arr[row + 1][column] == cur && check[row + 1][column] == 0)
	{
		check[row + 1][column] = 1;
		is_same(num, row + 1, column);
	}
	if (row != 0 && arr[row - 1][column] == cur && check[row - 1][column] == 0)
	{
		check[row - 1][column] = 1;
		is_same(num, row - 1, column);
	}
	if (column < num - 1 && arr[row][column + 1] == cur && check[row][column + 1] == 0)
	{
		check[row][column + 1] = 1;
		is_same(num, row, column + 1);
	}
	if (column != 0 && arr[row][column - 1] == cur && check[row][column - 1] == 0)
	{
		check[row][column - 1] = 1;
		is_same(num, row, column - 1);
	}
}

static int	district(int num)
{
	int	row, column, count = 0;

	row = -1;
	while (++row < num)
	{
		column = -1;
		while (++column < num)
		{
			if (check[row][column] == 0)
			{
				count++;
				is_same(num, row, column);
			}
		}
	}
	return (count);
}

int	main()
{
	int		num, idx, temp;
	
	scanf("%d", &num);
	arr = (char **)malloc(num * sizeof(char *));
	check = (bool **)malloc(num * sizeof(bool *));

	idx = -1;
	while (++idx < num)
	{
		arr[idx] = (char *)malloc(num * sizeof(char));
		check[idx] = (bool *)calloc(num, sizeof(bool));
		scanf("%s", arr[idx]);
	}

	printf("%d ", district(num));
	
	idx = -1;
	while (++idx < num)
	{
		memset(check[idx], 0, sizeof(bool) * num);
		temp = -1;
		while (++temp < num)
		{
			if (arr[idx][temp] == 'G')
				arr[idx][temp] = 'R';
		}
	}
	printf("%d", district(num));

	idx = -1;
	while (++idx < num)
	{
		free(arr[idx]);
		free(check[idx]);
	}
	free(arr);
	free(check);

	return (0);
}
