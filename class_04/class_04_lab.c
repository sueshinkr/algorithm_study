#include <stdio.h>
#define MIN(x, y) ((x < y) ? (x) : (y))

struct que
{
	int	r;
	int	c;
};

int	row, column, min = 64;

static int	count_safe(int arr[8][8])
{
	int	front = 0, rear = 0;
	int	r, c, count = 0;
	int	temp_arr[8][8];
	struct que q[64];

	r = -1;
	while (++r < row)
	{
		c = -1;
		while (++c < column)
			temp_arr[r][c] = arr[r][c];
	}

	r = -1;
	while (++r < row)
	{
		c = -1;
		while (++c < column)
		{
			if (temp_arr[r][c] == 2)
			{
				q[rear].r = r;
				q[rear++].c = c;
			}
		}
	}

	while (front < rear)
	{ 	
		if (q[front].r < row - 1 && temp_arr[q[front].r + 1][q[front].c] == 0)
		{
			temp_arr[q[front].r + 1][q[front].c] = 2;
			q[rear].r = q[front].r + 1;
			q[rear++].c = q[front].c;
			count++;
		}
		if (q[front].r > 0 && temp_arr[q[front].r - 1][q[front].c] == 0)
		{
			temp_arr[q[front].r - 1][q[front].c] = 2;
			q[rear].r = q[front].r - 1;
			q[rear++].c = q[front].c;
			count++;
		}

		if (q[front].c < column - 1 && temp_arr[q[front].r][q[front].c + 1] == 0)
		{
			temp_arr[q[front].r][q[front].c + 1] = 2;
			q[rear].r = q[front].r;
			q[rear++].c = q[front].c + 1;
			count++;
		}
		if (q[front].c > 0 && temp_arr[q[front].r][q[front].c - 1] == 0)
		{
			temp_arr[q[front].r][q[front].c - 1] = 2;
			q[rear].r = q[front].r;
			q[rear++].c = q[front].c - 1;
			count++;
		}
		front++;
	}

	return (count);
}


static void	make_wall(int arr[8][8], int r, int c, int count)
{
	int temp_r, temp_c, ans;

	temp_r = r - 1;
	while (++temp_r < row)
	{
		temp_c = temp_r == r ? c : -1;

		while (++temp_c < column)
		{
			if (arr[temp_r][temp_c] == 0)
			{
				arr[temp_r][temp_c] = 1;
				count++;
				if (count < 3)
				{
					make_wall(arr, temp_r, temp_c, count);
					arr[temp_r][temp_c] = 0;
					count--;
				}
				else
				{
					ans = count_safe(arr);
					min = MIN(min, ans);
					arr[temp_r][temp_c] = 0;
				}
			}
		}
	}
}

int	main()
{
	int	r, c, count = 0;
	int	arr[8][8];
	
	scanf("%d %d", &row, &column);

	r = -1;
	while (++r < row)
	{
		c = -1;
		while (++c < column)
		{
			scanf("%d", &arr[r][c]);
			if (arr[r][c] == 0)
				count++;
		}
	}

	make_wall(arr, 0, -1, 0);
	printf("%d\n", count - min - 3);
}
