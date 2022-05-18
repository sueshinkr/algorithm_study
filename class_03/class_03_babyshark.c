#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct que
{
	int row;
	int column;
	int count;
} q;

int		n, **arr, size = 2, eat = 0, ans = 0;
bool	**check;
q		que[400];

static void	bfs(int row, int column)
{
	int	front = 0, rear = 0;
	int	idx, fr, fc;
	que[0].row = row;
	que[0].column = column;
	que[0].count = 0;
	arr[row][column] = 0;
	check[row][column] = 1;

	while (front <= rear)
	{
		printf("[%d][%d],COUNT : %d\n", que[front].row + 1, que[front].column + 1, que[front].count);
		if (arr[que[front].row][que[front].column] != 0 && arr[que[front].row][que[front].column] < size)
		{
			printf(":::::::::\n");
			printf("(%d, %d), count : %d\n", que[front].row + 1, que[front].column + 1, que[front].count);
			eat++;
			if (eat == size)
			{
				size++;
				eat = 0;
			}
			printf("eat : %d, size : %d\n", eat, size);
/*
			if (arr[que[front].row][que[front].column] == size - 1)
			{
				
			}
*/
			arr[que[front].row][que[front].column] = 0;
			ans += que[front].count;
			printf("ans : %d\n", ans);
			que[0].row = que[front].row;
			que[0].column = que[front].column;
			que[0].count = 0;
			front = 0, rear = 0;
			
			idx = -1;
			while (++idx < n)
				memset(check[idx], 0, n * sizeof(bool));
			/*
			row = -1;
			while (++row < n)
			{
				column = -1;
				while (++column < n)
					printf("%d ", check[row][column]);
				printf("\n");
			}
			*/

		check[que[0].row][que[0].column] = true;
		}

		fr = que[front].row;
		fc = que[front].column;

		if (fr > 0 && arr[fr - 1][fc] <= size && !check[fr - 1][fc])
		{
			check[fr - 1][fc] = true;
			que[++rear].row = fr - 1;
			que[rear].column = fc;
			que[rear].count = que[front].count + 1;
		}
		if (fc > 0  && arr[fr][fc - 1] <= size && !check[fr][fc - 1])
		{
			check[fr][fc - 1] = true;
			que[++rear].row = fr;
			que[rear].column = fc - 1;
			que[rear].count = que[front].count + 1;
		}
		if (fc < n - 1 && arr[fr][fc + 1] <= size && !check[fr][fc + 1])
		{
			check[fr][fc + 1] = true;
			que[++rear].row = fr;
			que[rear].column = fc + 1;
			que[rear].count = que[front].count + 1;
		}
		if (fr < n - 1 && arr[fr + 1][fc] <= size && !check[fr + 1][fc])
		{
			if (front == 0 || (fr != que[0].row && front != 0))
			{
				check[fr + 1][fc] = true;
				que[++rear].row = fr + 1;
				que[rear].column = fc;
				que[rear].count = que[front].count + 1;
			}
		}
		front++;
	}
}

int	main()
{
	int row, column;

	scanf("%d", &n);
	arr = (int **)malloc(n * sizeof(int *));
	check = (bool **)malloc(n * sizeof(bool *));

	row = -1;
	while (++row < n)
	{
		arr[row] = (int *)malloc(n * sizeof(int));
		check[row] = (bool *)calloc(n, sizeof(bool));

		column = -1;
		while (++column < n)
			scanf("%d", &arr[row][column]);
	}

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
		{
			if (arr[row][column] == 9)
				bfs(row, column);
		}
	}

	printf("%d", ans);
	return (0);
}

/*
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6

6
5 4 3 0 3 4
4 3 0 3 4 5
3 2 0 5 6 6
2 0 0 3 4 5
3 2 0 6 5 4
6 6 6 6 6 6




6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1

6
6 0 6 0 6 0
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 0
*/



