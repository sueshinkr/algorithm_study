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
	int	idx, fr, fc, temp;
	que[0].row = row;
	que[0].column = column;
	que[0].count = 0;
	arr[row][column] = 0;
	check[row][column] = 1;

	while (front <= rear)
	{
		idx = 0;
		while (front + idx < rear && que[front].count == que[front + idx].count)
		{
			if (que[front].row > que[front + idx].row || (que[front].row == que[front + idx].row && que[front].column > que[front + idx].column))
			{
				temp = que[front].row;
				que[front].row = que[front + idx].row;
				que[front + idx].row = temp;
				temp = que[front].column;
				que[front].column = que[front + idx].column;
				que[front + idx].column = temp;
				break;
			}
			idx++;
		}

		if (arr[que[front].row][que[front].column] != 0 && arr[que[front].row][que[front].column] < size)
		{
			
			eat++;
			if (eat == size)
			{
				size++;
				eat = 0;
			}

			arr[que[front].row][que[front].column] = 0;
			ans += que[front].count;
			
			que[0].row = que[front].row;
			que[0].column = que[front].column;
			que[0].count = 0;
			memset(que + 1, 0, sizeof(que) - sizeof(que[0]));
			
			idx = -1;
			while (++idx < n)
				memset(check[idx], 0, n * sizeof(bool));
			front = 0, rear = 0;
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
			check[fr + 1][fc] = true;
			que[++rear].row = fr + 1;
			que[rear].column = fc;
			que[rear].count = que[front].count + 1;
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
printf("[%d][%d],COUNT : %d\n", que[front].row + 1, que[front].column + 1, que[front].count);
printf(":::::::::\n");
printf("(%d, %d), count : %d\n", que[front].row + 1, que[front].column + 1, que[front].count);
printf("eat : %d, size : %d\n", eat, size);
printf("ans : %d\n", ans);




3 6 6 1 5 3
1 6 1 5 2 4
6 1 2 2 1 5
4 0 0 1 6 3
2 0 5 4 0 0
1 0 9 0 0 3

6
3 6 6 1 5 0
1 6 0 5 0 4
6 0 0 0 0 5
4 0 0 0 6 3
2 0 5 ! 0 0
0 0 0 0 0 3



63


7
2 0 6 ! 0 4 1
2 0 0 0 0 6 1
3 5 1 0 2 5 0
3 0 0 9 0 0 4
6 1 1 0 2 1 6
0 0 4 0 4 1 2
5 0 0 0 4 0 2

59
*/



