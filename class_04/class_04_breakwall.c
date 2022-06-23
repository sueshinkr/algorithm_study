#include <stdio.h>
#include <stdbool.h>
#define max 1001*1001*2

struct que
{
	int r, c;
	int dis, breakwall;
};

int		n, m;
int		arr[1001][1001] = {0, };
bool	check[1001][1001][2] = {0, };
struct que q[max] = {0, };

static void	cal_mindis()
{
	int	row, column, dis, breakwall, idx;
	int	front = 0, rear = 1;
	int	row_plus[] = {1, 0, -1, 0};
	int	column_plus[] = {0, 1, 0, -1};

	if (n == 1 && m == 1)
	{
		printf("1\n");
		return ;
	}

	check[1][1][0] = 1;
	check[1][1][1] = 1;

	q[front].r = 1;
	q[front].c = 1;
	q[front].dis = 1;
	q[front].breakwall = 0;

	while (front < rear)
	{
		row = q[front].r;
		column = q[front].c;
		dis = q[front].dis;
		breakwall = q[front++].breakwall;
		//front %= max;

		idx = -1;
		while (++idx < 4)
		{
			if (row + row_plus[idx] >= 1 && row + row_plus[idx] <= n && column + column_plus[idx] >= 1 && column + column_plus[idx] <= m)
			{
				if (row + row_plus[idx] == n && column + column_plus[idx] == m)
				{
					printf("%d\n", dis + 1);
					return ;
				}

				if (arr[row + row_plus[idx]][column + column_plus[idx]] == 0)
				{
					if (check[row + row_plus[idx]][column + column_plus[idx]][breakwall] == 0)
					{
						q[rear].breakwall = breakwall;
						q[rear].r = row + row_plus[idx];
						q[rear].c = column + column_plus[idx];
						q[rear++].dis = dis + 1;
						//rear %= max;
						check[row + row_plus[idx]][column + column_plus[idx]][breakwall] = 1;
					}
				}
				else if (arr[row + row_plus[idx]][column + column_plus[idx]] == 1)
				{
					if (breakwall == 0 && check[row + row_plus[idx]][column + column_plus[idx]][0] == 0)
					{
						q[rear].breakwall = 1;
						q[rear].r = row + row_plus[idx];
						q[rear].c = column + column_plus[idx];
						q[rear++].dis = dis + 1;
						//rear %= max;
						check[row + row_plus[idx]][column + column_plus[idx]][1] = 1;
					}
				}
			}
		}
	}
	printf("-1\n");
	return ;
}

int	main()
{
	int	row, column;

	scanf("%d %d", &n, &m);

	row = 0;
	while (++row <= n)
	{
		column = 0;
		while (++column <= m)
			scanf("%1d", &arr[row][column]);
	}

	cal_mindis();
	return (0);
}
