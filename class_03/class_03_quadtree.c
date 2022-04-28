#include <stdio.h>
#include <stdlib.h>

int	**arr;

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
			printf("(");
			column_temp = 2;
			while (--column_temp >= 0)
			{
				row_temp = 2;
				while (--row_temp >= 0)
					recur_tree(size / 2, row - size / 2 * row_temp, column - size / 2 * column_temp);
			}
			printf(")");
		}
		else
			printf("%d", arr[column - 1][row - 1] % 10);
	}
	else
	{
		if (arr[column - 1][row - 1] <= 1)
			printf("%d", arr[column - 1][row - 1]);
		else if (arr[column - 1][row - 1] % 20 <= 1)
			printf("%d", arr[column - 1][row - 1] % 20);
		else
		{
			printf("(");
			column_temp = 2;
			while (--column_temp >= 0)
			{
				row_temp = 2;
				while (--row_temp >= 0)
					printf("%d", arr[column - column_temp - 1][row - row_temp - 1] % 10);
			}
			printf(")");
		}
	}
}

int main()
{
	int num, idx, temp;
	char	temp_str[64];

	scanf("%d", &num);
	arr = (int **)malloc(num * sizeof(int *));

	idx = -1;
	while (++idx < num)
	{
		scanf("%s", temp_str);
		arr[idx] = (int *)malloc(num * sizeof(int));
		temp = -1;
		while (++temp < num)
			arr[idx][temp] = temp_str[temp] - '0';
	}

	recur_check(num, num, num);
	recur_tree(num, num, num);

	idx = -1;
	while (++idx < num)
		free(arr[idx]);
	free(arr);
	return (0);
}

/*
	printf(":::::::::::::::::::::\n");
	idx = -1;
	while (++idx < num)
	{
		temp = -1;
		while (++temp < num)
			printf("%d ", arr[idx][temp]);
		printf("\n");
	}
	printf(":::::::::::::::::::::\n");
//printf("arr[%d][%d] : %d\n", column - size / 2 * column_temp - 1, row - size / 2 * row_temp - 1, arr[column - size / 2 * column_temp - 1][row - size / 2 * row_temp - 1]);
*/
