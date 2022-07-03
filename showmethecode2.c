#include <stdio.h>

int	arr[7][7];
int	row_check[7] = {0, };
int	column_check[7] = {0, };
int	ball_num = 0;
int drop_num;
int min_ball = 7 * 7;

static void check(int column_num, int ball)
{
	int	temp_arr[7][7] = {0, };
	int	temp_row_check[7] = {0, }, row_minus[7] = {0, };
	int	temp_column_check[7] = {0, }, column_minus[7] = {0, };
	int	row, column, temp;
	int repeat = 1;

	row = -1;
	{
		while (++row < 7)
		{
			column = -1;
			while (++column < 7)
				temp_arr[row][column] = arr[row][column];
			temp_row_check[row] = row_check[row];
			temp_column_check[row] = column_check[row];
		}
	}

	row = 7;
	while (--row > -1)
	{
		if (temp_arr[row][column_num] == 0)
		{
			temp_arr[row][column_num] = drop_num;
			temp_column_check[column_num]++;
			temp_row_check[row]++;
			break;
		}
	}

	while (repeat == 1)
	{
		repeat = 0;
		row = -1;
		while (++row < 7)
		{
			column = -1;
			while (++column < 7)
			{
				if (temp_arr[row][column] != 0 && (temp_arr[row][column] == temp_column_check[column] || temp_arr[row][column] == temp_row_check[row]))
				{
					repeat = 1;
					ball--;
					column_minus[column]++;
					row_minus[row]++;
					temp_arr[row][column] = 0;
					if (row != 0 && temp_arr[row - 1][column] != 0)
					{
						temp = row;
						while (--temp >= 0 && temp_arr[temp][column] != 0)
						{
							temp_arr[temp + 1][column] = temp_arr[temp][column];
							temp_arr[temp][column] = 0;
							row_minus[temp]++;
							row_minus[temp + 1]--;
						}
					}
				}
			}
		}

		temp = -1;
		while(++temp < 7)
		{
			temp_column_check[temp] -= column_minus[temp];
			temp_row_check[temp] -= row_minus[temp];
			column_minus[temp] = 0;
			row_minus[temp] = 0;
		}
	}

	if (ball < min_ball)
		min_ball = ball;

	return ;
}

int main()
{
	int row, column;

	row = -1;
	while (++row < 7)
	{
		column = -1;
		while (++column < 7)
		{
			scanf("%d", &arr[row][column]);
			if (arr[row][column] != 0)
			{
				row_check[row]++;
				column_check[column]++;
				ball_num++;
			}
		}
	}

	scanf("%d", &drop_num);

	column = -1;
	while(++column < 7)
	{
		if (arr[0][column] == 0)
			check(column, ball_num);
	}

	printf("%d\n", min_ball + 1);
}