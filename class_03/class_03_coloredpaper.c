#include <stdio.h>
#include <stdlib.h>

int	**arr, count[2] = {0, 0};

static void recur_check(int size, int row, int column)
{
	int	row_temp, column_temp, count_temp[2] = {0, 0};

	if (size > 2)
	{
		column_temp = 2;
		while (--column_temp >= 0)
		{
			row_temp = 2;
			while (--row_temp >= 0)
				recur_check(size / 2, row - size / 2 * row_temp, column - size / 2 * column_temp);
		}

		column_temp = 2;
		while (--column_temp >= 0)
		{
			row_temp = 2;
			while (--row_temp >= 0)
			{	
				if (arr[column - size / 2 * column_temp - 1][row - size / 2 * row_temp - 1] == 0)
					count_temp[0]++;
				else if (arr[column - size / 2 * column_temp - 1][row - size / 2 * row_temp - 1] == 1)
					count_temp[1]++;
			}
		}
		if (count_temp[0] != 4 && count_temp[1] != 4)
			arr[column - 1][row - 1] += 10 * size;
	}
	else
	{
		row_temp = -1;
		while (++row_temp < 2)
		{
			column_temp = -1;
			while (++column_temp < 2)
				count_temp[arr[column - column_temp - 1][row - row_temp - 1]]++;
		}

		if (count_temp[0] != 4 && count_temp[1] != 4)
			arr[column - 1][row - 1] += 10;
		return ;
	}
}

static void recur_tree(int size, int row, int column)
{
	int	row_temp, column_temp, flag = 0;

	if (size > 2)
	{
		column_temp = 2;
		while (--column_temp >= 0)
		{
			row_temp = 2;
			while (--row_temp >= 0)
			{
				if (arr[column - size / 2 * column_temp - 1][row - size / 2 * row_temp - 1] >= 10)
					flag = 1;
			}
		}
		if (flag == 1 && arr[column - 1][row - 1] % (size * 20) > 1)
		{
			column_temp = 2;
			while (--column_temp >= 0)
			{
				row_temp = 2;
				while (--row_temp >= 0)
					recur_tree(size / 2, row - size / 2 * row_temp, column - size / 2 * column_temp);
			}
		}
		else
			count[arr[column - 1][row - 1] % 10]++;
	}
	else
	{
		if (arr[column - 1][row - 1] <= 1)
			count[arr[column - 1][row - 1]]++;
		else if (arr[column - 1][row - 1] % 20 <= 1)
			count[arr[column - 1][row - 1] % 20]++;
		else
		{
			column_temp = 2;
			while (--column_temp >= 0)
			{
				row_temp = 2;
				while (--row_temp >= 0)
					count[arr[column - column_temp - 1][row - row_temp - 1] % 10]++;
			}
		}
	}
}

int main()
{
	int num, idx, temp;

	scanf("%d", &num);
	arr = (int **)malloc(num * sizeof(int *));

	idx = -1;
	while (++idx < num)
	{
		arr[idx] = (int *)malloc(num * sizeof(int));
		temp = -1;
		while (++temp < num)
			scanf("%d", &arr[idx][temp]);
	}

	recur_check(num, num, num);
	recur_tree(num, num, num);

	printf("%d\n%d", count[0], count[1]);
	idx = -1;
	while (++idx < num)
		free(arr[idx]);
	free(arr);
	return (0);
}