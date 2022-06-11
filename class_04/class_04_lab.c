#include <stdio.h>
#define MAX(x, y) ((x > y) ? (x) : (y))

struct que
{
	int	r;
	int	c;
};

int	row, column, max;

static int	count_safe(int arr[8][8])
{
	int	front = 0, rear = 0;
	int	r, c, count = 0;
	struct que q[64];

	r = -1;
	while (++r < row)
	{
		c = -1;
		while (++c < column)
		{
			if (arr[r][c] == 2)
			{
				q[rear].r = r;
				q[rear++].c = c;
				count++;
			}
		}
	}

	printf(":::::::::::::::::::\n");
	r = -1;
	while (++r < row)
	{
		c = -1;
		while (++c < column)
			printf("%d ", arr[r][c]);
		printf("\n");
	}
	printf(":::::::::::::::::::\n");

	while (front < rear)
	{ 	
		if (q[front].r < row - 1 && arr[q[front].r + 1][q[front].c] == 0)
		{
			arr[q[front].r + 1][q[front].c] = 2;
			q[rear].r = q[front].r + 1;
			q[rear++].c = q[front].c;
			count++;
		}
		if (q[front].r > 0 && arr[q[front].r - 1][q[front].c] == 0)
		{
			arr[q[front].r - 1][q[front].c] = 2;
			q[rear].r = q[front].r - 1;
			q[rear++].c = q[front].c;
			count++;
		}

		if (q[front].c < column - 1 && arr[q[front].r][q[front].c + 1] == 0)
		{
			arr[q[front].r][q[front].c + 1] = 2;
			q[rear].r = q[front].r;
			q[rear++].c = q[front].c + 1;
			count++;
		}
		if (q[front].c > 0 && arr[q[front].r][q[front].c - 1] == 0)
		{
			arr[q[front].r][q[front].c - 1] = 2;
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
	int temp_r, temp_c;
	int rr, cc;

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
					max = MAX(max, count_safe(arr));
					arr[temp_r][temp_c] = 0;
				}
			}
		}
	}
}

int	main()
{
	int	r, c;
	int	arr[8][8];
	
	scanf("%d %d", &row, &column);

	r = -1;
	while (++r < row)
	{
		c = -1;
		while (++c < column)
			scanf("%d", &arr[r][c]);
	}

	make_wall(arr, 0, -1, 0);
	printf("%d\n", max);
}