#include <stdio.h>
#include <stdlib.h>

static void	check_adjoin(int **arr, int row_idx, int column_idx, int row, int column)
{
	if (row_idx != row - 1 && arr[row_idx + 1][column_idx] == 1)
	{
		arr[row_idx + 1][column_idx] = 2;
		check_adjoin(arr, row_idx + 1, column_idx, row, column);
	}
	if (row_idx != 0 && arr[row_idx - 1][column_idx] == 1)
	{
		arr[row_idx - 1][column_idx] = 2;
		check_adjoin(arr, row_idx - 1, column_idx, row, column);
	}
	if (column_idx != column - 1 && arr[row_idx][column_idx + 1] == 1)
	{
		arr[row_idx][column_idx + 1] = 2;
		check_adjoin(arr, row_idx, column_idx + 1, row, column);
	}
	if (column_idx != 0 && arr[row_idx][column_idx - 1] == 1)
	{
		arr[row_idx][column_idx - 1] = 2;
		check_adjoin(arr, row_idx, column_idx - 1, row, column);
	}
}

int main()
{
	int	test_num, row, column, cabbage, **arr;
	int	row_idx, column_idx, count;

	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d %d %d", &row, &column, &cabbage);
		arr = (int **)malloc(row * sizeof(int *));
		row_idx = -1;
		while (++row_idx < row)
			arr[row_idx] = (int *)calloc(column, sizeof(int));
		
		while (cabbage-- > 0)
		{
			scanf("%d %d", &row_idx, &column_idx);
			arr[row_idx][column_idx] = 1;
		}

		count = 0;
		row_idx = -1;
		while (++row_idx < row)
		{
			column_idx = -1;
			while (++column_idx < column)
			{
				if (arr[row_idx][column_idx] == 1)
				{
					count++;
					check_adjoin(arr, row_idx, column_idx, row, column);
				}
			}
		}

		row_idx = -1;
		while (++row_idx < row)
			free(arr[row_idx]);
		free(arr);
		printf("%d\n", count);
	}

	return (0);
}
