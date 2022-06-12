#include <stdio.h>
#include <string.h>
#define MIN(x, y) ((x < y) ? (x) : (y))

struct que
{
	int	r;
	int	c;
	int	dis;
};

int	n, m, min = 10000;

static int	cal_dis(int arr[50][50])
{
	int	front, rear;
	int	temp_arr[50][50], check[50][50];
	int	r, c, total_dis = 0;
	struct que q[100000];

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
			temp_arr[r][c] = arr[r][c];
	}

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
		{

			if (temp_arr[r][c] == 1)
			{
				front = 0, rear = 0;
				
				memset(check, 0, sizeof(check));
				check[r][c] = 1;
				q[rear].dis = 0;
				q[rear].r = r;
				q[rear++].c = c;

				while (front < rear)
				{
					if ((q[front].r < n - 1 && temp_arr[q[front].r + 1][q[front].c] == 2)
						|| (q[front].r > 0 && temp_arr[q[front].r - 1][q[front].c] == 2)
						|| (q[front].c < n - 1 && temp_arr[q[front].r][q[front].c + 1] == 2)
						|| (q[front].c > 0 && temp_arr[q[front].r][q[front].c - 1] == 2))
					{
						total_dis += q[front].dis + 1;
						break;
					}
					else
					{
						if (q[front].r < n - 1 && check[q[front].r + 1][q[front].c] == 0 && temp_arr[q[front].r + 1][q[front].c] != 2)
						{
							check[q[front].r + 1][q[front].c] = 1;
							q[rear].dis = q[front].dis + 1;
							q[rear].r = q[front].r + 1;
							q[rear++].c = q[front].c;
						}
						if (q[front].r > 0 && check[q[front].r - 1][q[front].c] == 0 && temp_arr[q[front].r - 1][q[front].c] != 2)
						{
							check[q[front].r - 1][q[front].c] = 1;
							q[rear].dis = q[front].dis + 1;
							q[rear].r = q[front].r - 1;
							q[rear++].c = q[front].c;
						}

						if (q[front].c < n - 1 && check[q[front].r][q[front].c + 1] == 0 && temp_arr[q[front].r][q[front].c + 1] != 2)
						{
							check[q[front].r][q[front].c + 1] = 1;
							q[rear].dis = q[front].dis + 1;
							q[rear].r = q[front].r;
							q[rear++].c = q[front].c + 1;
						}
						if (q[front].c > 0 && check[q[front].r][q[front].c - 1] == 0 && temp_arr[q[front].r][q[front].c - 1] != 2)
						{
							check[q[front].r][q[front].c - 1] = 1;
							q[rear].dis = q[front].dis + 1;
							q[rear].r = q[front].r;
							q[rear++].c = q[front].c - 1;
						}
						front++;
					}
				}
			}
		}
	}
	return (total_dis);
}

static void	select_store(int arr[50][50], int r, int c, int count)
{
	int row, column, total_dis;

	if (count <= m)
	{
		total_dis = cal_dis(arr);
		min = MIN(min, total_dis);
		return ;
	}

	row = r - 1;
	while (++row < n)
	{
		column = row == r ? c : -1;

		while (++column < n)
		{
			if (arr[row][column] == 2)
			{
				arr[row][column] = 0;
				select_store(arr, row, column, count - 1);
				arr[row][column] = 2;
			}
		}
	}
}

int	main()
{
	int	r, c, count = 0;
	int	arr[50][50];
	
	scanf("%d %d", &n, &m);

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
		{
			scanf("%d", &arr[r][c]);
			if (arr[r][c] == 2)
				count++;
		}
	}

	select_store(arr, 0, -1, count);
	printf("%d\n", min);
}
