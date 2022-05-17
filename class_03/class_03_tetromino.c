#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int		n, m, **arr, ans = 0;
bool	**check;

static void dfs(int row, int column, int length, int sum)
{
	sum += arr[row][column];
	if (length == 4)
	{
		if (sum > ans)
			ans = sum;
		return ;
	}

	if (row > 0 && !check[row - 1][column])
	{
		check[row - 1][column] = true;
		dfs(row - 1, column, length + 1, sum);
		check[row - 1][column] = false;
	}
	if (row < n - 1 && !check[row + 1][column])
	{
		check[row + 1][column] = true;
		dfs(row + 1, column, length + 1, sum);
		check[row + 1][column] = false;
	}
	if (column > 0 && !check[row][column - 1])
	{
		check[row][column - 1] = true;
		dfs(row, column - 1, length + 1, sum);
		check[row][column - 1] = false;
	}
	if (column < m - 1 && !check[row][column + 1])
	{
		check[row][column + 1] = true;
		dfs(row, column + 1, length + 1, sum);
		check[row][column + 1] = false;
	}
}

static void	check_f(int row, int column)
{
	int	sum;

	if (row < n - 2 && column < m - 1)
	{
		sum = 0;
		sum += arr[row][column] + arr[row + 1][column] + arr[row + 1][column + 1] + arr[row + 2][column];
		if (sum > ans)
			ans = sum;
	}
	if (row < n - 2 && column > 0)
	{
		sum = 0;
		sum += arr[row][column] + arr[row + 1][column] + arr[row + 1][column - 1] + arr[row + 2][column];
		if (sum > ans)
			ans = sum;
	}
	if (row < n - 1 && column < m - 2)
	{
		sum = 0;
		sum += arr[row][column] + arr[row][column + 1] + arr[row + 1][column + 1] + arr[row][column + 2];
		if (sum > ans)
			ans = sum;
	}
	if (row > 0 && column < m - 2)
	{
		sum = 0;
		sum += arr[row][column] + arr[row][column + 1] + arr[row - 1][column + 1] + arr[row][column + 2];
		if (sum > ans)
			ans = sum;
	}
}

int	main()
{
	int	row_idx, column_idx, length = 1, sum = 0;

	scanf("%d %d", &n, &m);
	arr = (int **)malloc((n * m) * sizeof(int *));
	check = (bool **)malloc((n * m) * sizeof(bool *));

	row_idx = -1;
	while (++row_idx < n)
	{
		arr[row_idx] = (int *)malloc(m * sizeof(int));
		check[row_idx] = (bool *)calloc(m, sizeof(bool));

		column_idx = -1;
		while (++column_idx < m)
			scanf("%d", &arr[row_idx][column_idx]);
	}

	row_idx = -1;
	while (++row_idx < n)
	{
		column_idx = -1;
		while (++column_idx < m)
		{	
			check[row_idx][column_idx] = true;
			dfs(row_idx, column_idx, length, sum);
			check[row_idx][column_idx] = false;
			check_f(row_idx, column_idx);
		}
	}

	printf("%d\n", ans);
	row_idx = -1;
	while (++row_idx < n)
	{
		free(arr[row_idx]);
		free(check[row_idx]);
	}
	free(arr);
	free(check);
	return (0);
}
