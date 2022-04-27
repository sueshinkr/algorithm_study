#include <stdio.h>
#include <stdlib.h>

int	countm1 = 0, count0 = 0, count1 = 0;
int **arr;

static void recur_count(int num, int column_idx, int row_idx)
{
	int	row, column, temp;
	int	countm1_temp = 0, count0_temp = 0, count1_temp = 0;

	if (num > 3)
	{
		row = -1;
		while (++row < 3)
		{
			column = -1;
			while (++column < 3)
				recur_count(num / 3, column_idx - column * num / 3, row_idx - row * num / 3);
		}
		
		//printf("num : %d\n", num);
		//printf("arr[%d][%d]\n", column_idx, row_idx);
		//printf(":: before %d // %d // %d\n", countm1, count0, count1);
		row = -1;
		while (++row < 3)
		{
			column = -1;
			while (++column < 3)
			{	
				temp = arr[column_idx - column * num / 3 - 1][row_idx - row * num / 3 - 1];
				if (temp == -1)
					countm1_temp++;
				else if (temp == 0)
					count0_temp++;
				else if (temp == 1)
					count1_temp++;
				else
				{
					arr[column_idx -1][row_idx - 1] = 2;
					return ;
				}
			}
		}
		if (countm1_temp == 9)
			countm1 -= 8;
		else if (count0_temp == 9)
			count0 -= 8;
		else if (count1_temp == 9)
			count1 -= 8;
		else
			arr[column_idx -1][row_idx - 1] = 2;

		
		//printf(":: after %d // %d // %d\n", countm1, count0, count1);
	}
	else
	{
		row = -1;
		while (++row < 3)
		{
			column = -1;
			while (++column < 3)
			{
				temp = arr[column_idx - column * num / 3 - 1][row_idx - row * num / 3 - 1];
				printf("arr[%d][%d] : %d\n", column_idx - column * num / 3, row_idx - row * num / 3, temp);
				if (temp == -1)
					countm1_temp++;
				else if (temp == 0)
					count0_temp++;
				else if (temp == 1)
					count1_temp++;
			}
		}

		if (countm1_temp == 9)
			countm1++;
		else if (count0_temp == 9)
			count0++;
		else if (count1_temp == 9)
			count1++;
		else
		{
			countm1 += countm1_temp;
			count0 += count0_temp;
			count1 += count1_temp;
			arr[column_idx - 1][row_idx - 1] = 2;
		}
		printf("%d\n%d\n%d\n", countm1, count0, count1);

	}
}
int main()
{
	int num, idx, arr_idx;
	
	scanf("%d", &num);
	arr = (int **)malloc(num * sizeof(int *));

	idx = -1;
	while (++idx < num)
	{	
		arr[idx] = (int *)malloc(num * sizeof(int));
		arr_idx = -1;
		while (++arr_idx < num)
			scanf("%d", &arr[idx][arr_idx]);
	}

	recur_count(num, num, num);
	printf("%d\n%d\n%d\n", countm1, count0, count1);

	idx = -1;
	while (++idx < num)
		free(arr[idx]);
	free(arr);
	
	return (0);
}
