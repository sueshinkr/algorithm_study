#include <stdio.h>
#define max 1000*1000*2

struct que
{
	int r, c;
	int dis, breakwall;
};

int	n, m, mindis = 1001;
int	arr[1001][1001] = {0, };
int	check[1001][1001][2] = {0, };

static void	cal_mindis()
{
	int	row, column, dis, breakwall;
	int	front = 0, rear = 1;
	struct que q[max];

	check[0][0][0] = 1;
	check[0][0][1] = 1;

	q[front].r = 0;
	q[front].c = 0;
	q[front].dis = 1;
	q[front].breakwall = 0;

	while (front != rear)
	{
		row = q[front].r;
		column = q[front].c;
		dis = q[front].dis;
		breakwall = q[front++].breakwall;
		front %= max;

		if (row == n - 1 && column == m - 1)
		{
			printf("%d\n", dis);
			return ;
		}

		if (row > 0)
		{
			if (arr[row - 1][column] == 0)
			{
				if (check[row - 1][column][breakwall] == 0)
				{
					q[rear].breakwall = breakwall;
					q[rear].r = row - 1;
					q[rear].c = column;
					q[rear++].dis = dis + 1;
					check[row - 1][column][breakwall] = 1;
				}
			}
			else if (arr[row - 1][column] == 1)
			{
				if (breakwall == 0 && check[row - 1][column][0] == 0)
				{
					q[rear].breakwall = 1;
					q[rear].r = row - 1;
					q[rear].c = column;
					q[rear++].dis = dis + 1;
					check[row - 1][column][1] = 1;
				}
			}
			rear %= max;
		}
		if (row < n - 1)
		{
			if (arr[row + 1][column] == 0)
			{
				if (check[row + 1][column][breakwall] == 0)
				{
					q[rear].breakwall = breakwall;
					q[rear].r = row + 1;
					q[rear].c = column;
					q[rear++].dis = dis + 1;
					check[row + 1][column][breakwall] = 1;
				}
			}
			else if (arr[row + 1][column] == 1)
			{
				if (breakwall == 0 && check[row + 1][column][0] == 0)
				{
					q[rear].breakwall = 1;
					q[rear].r = row + 1;
					q[rear].c = column;
					q[rear++].dis = dis + 1;
					check[row + 1][column][1] = 1;
				}
			}
			rear %= max;
		}
		if (column > 0)
		{
			if (arr[row][column - 1] == 0)
			{
				if (check[row][column - 1][breakwall] == 0)
				{
					q[rear].breakwall = breakwall;
					q[rear].r = row;
					q[rear].c = column - 1;
					q[rear++].dis = dis + 1;
					check[row][column - 1][breakwall] = 1;
				}
			}
			else if (arr[row][column - 1] == 1)
			{
				if (breakwall == 0 && check[row][column - 1][0] == 0)
				{
					q[rear].breakwall = 1;
					q[rear].r = row;
					q[rear].c = column - 1;
					q[rear++].dis = dis + 1;
					check[row][column - 1][1] = 1;
				}
			}
			rear %= max;
		}
		if (column < m - 1)
		{
			if (arr[row][column + 1] == 0)
			{
				if (check[row][column + 1][breakwall] == 0)
				{
					q[rear].breakwall = breakwall;
					q[rear].r = row;
					q[rear].c = column + 1;
					q[rear++].dis = dis + 1;
					check[row][column + 1][breakwall] = 1;
				}
			}
			else if (arr[row][column + 1] == 1)
			{
				if (breakwall == 0 && check[row][column + 1][0] == 0)
				{
					q[rear].breakwall = 1;
					q[rear].r = row;
					q[rear].c = column + 1;
					q[rear++].dis = dis + 1;
					check[row][column + 1][1] = 1;
				}
			}
			rear %= max;
		}
	}
	printf("-1\n");
	return ;
}

int	main()
{
	int	row, column;

	scanf("%d %d", &n, &m);

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < m)
			scanf("%1d", &arr[row][column]);
	}

	cal_mindis();
	return (0);
}
