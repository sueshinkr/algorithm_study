#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	buf[1000000] = {0, }, **tmt;
	int	row, column, height, row_idx, column_idx;
	int	new, loc, loc_temp, front = 0, rear = 0, count = 0;

	scanf("%d %d %d", &column, &row, &height);
	tmt = (int **)malloc(row * height * sizeof(int *));

	row_idx = -1;
	while (++row_idx < row * height)
	{
		tmt[row_idx] = (int *)malloc(column * sizeof(int));
		column_idx = -1;
		while (++column_idx < column)
		{
			scanf("%d", &tmt[row_idx][column_idx]);
			if (tmt[row_idx][column_idx] == 1)
				buf[rear++] = row_idx * column + column_idx;
		}
	}

	new = rear;
	while (front != rear)
	{
		loc = buf[front];
		loc_temp = buf[front++] % (row * column);

		if (loc_temp / column > 0 && !tmt[loc / column - 1][loc % column]) 
		{ // 현재 위치가 첫번째 행이 아닌경우 && 현재 위치의 윗칸이 0일경우
			buf[new++] = loc - column;
			tmt[loc / column - 1][loc % column]++;
		}
		if (loc_temp / column < row - 1 && !tmt[loc / column + 1][loc % column])
		{ // 현재 위치가 마지막 행이 아닌경우 && 현재 위치의 아랫칸이 0일경우
			buf[new++] = loc + column;
			tmt[loc / column + 1][loc % column]++;
		}
		if (loc_temp % column > 0 && !tmt[loc / column][loc % column - 1])
		{ // 현재 위치가 첫번째 열이 아닌경우 && 현재 위치의 왼쪽칸이 0일경우
			buf[new++] = loc - 1;
			tmt[loc / column][loc % column - 1]++;
		}
		if (loc_temp % column < column - 1 && !tmt[loc / column][loc % column + 1])
		{ // 현재 위치가 마지막 열이 아닌경우 && 현재 위치의 오른쪽칸이 0일경우
			buf[new++] = loc + 1;
			tmt[loc / column][loc % column + 1]++;
		}
		if (loc / column > row - 1 && !tmt[loc / column - row][loc % column])
		{ // 현재 위치가 첫번째 층이 아닌경우 && 현재 위치의 이전층이 0일경우
			buf[new++] = loc - row * column;
			tmt[loc / column - row][loc % column]++;
		}
		if (loc / column < row * (height - 1) && !tmt[loc / column + row][loc % column])
		{ // 현재 위치가 마지막 층이 아닌경우 && 현재 위치의 전층이 0일경우
			buf[new++] = loc + row * column;
			tmt[loc / column + row][loc % column]++;
		}

		if (front == rear)
		{
			count++;
			rear = new;
		}
	}

	if (count > 0)
		count--;
	row_idx = -1;
	while (++row_idx < row * height)
	{
		column_idx = -1;
		while (++column_idx < column)
		{
			if (!tmt[row_idx][column_idx])
			{
				count = -1;
				break;
			}
		}
		if (count == -1)
			break;
	}

	row_idx = -1;
	while (++row_idx < row * height)
		free(tmt[row_idx]);
	free(tmt);

	printf("%d\n", count);
	return (0);
}