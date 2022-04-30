#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	int	front, rear, count;
	struct queue	*data;
}	que;

static void find_by_bfs(bool **maze, int **check, int column, int row)
{
	int	cur_row, cur_column, cur_count = 1;
	que q;

	q.front = 0;
	q.rear = 0;
	q.data = (que *)calloc(row * column, sizeof(que));

	q.data[q.rear].front = 0;
	q.data[q.rear].rear = 0; 
	q.data[q.rear++].count = 1;
	check[0][0] = 1;

	while (q.rear > q.front)
	{
		cur_row = q.data[q.front].front;
		cur_column = q.data[q.front].rear;
		cur_count = q.data[q.front++].count;

		if (cur_row == row - 1 && cur_column == column - 1)
		{
			printf("%d", cur_count);
			break;
		}
		if (cur_row != row - 1 && maze[cur_column][cur_row + 1] == 1)
		{
			if (check[cur_column][cur_row + 1] == 0)
			{
				check[cur_column][cur_row + 1] = cur_count + 1;
				q.data[q.rear].front = cur_row + 1;
				q.data[q.rear].rear = cur_column;
				q.data[q.rear++].count = cur_count + 1;
			}
		}
		if (cur_column != column - 1 && maze[cur_column + 1][cur_row] == 1)
		{
			if (check[cur_column + 1][cur_row] == 0)
			{
				check[cur_column + 1][cur_row] = cur_count + 1;
				q.data[q.rear].front = cur_row;
				q.data[q.rear].rear = cur_column + 1;
				q.data[q.rear++].count = cur_count + 1;
			}
		}
		if (cur_row != 0 && maze[cur_column][cur_row - 1] == 1)
		{
			if (check[cur_column][cur_row - 1] == 0)
			{
				check[cur_column][cur_row - 1] = cur_count + 1;
				q.data[q.rear].front = cur_row - 1;
				q.data[q.rear].rear = cur_column;
				q.data[q.rear++].count = cur_count + 1;
			}
		}
		if (cur_column != 0 && maze[cur_column - 1][cur_row] == 1)
		{
			if (check[cur_column - 1][cur_row] == 0)
			{
				check[cur_column - 1][cur_row] = cur_count + 1;
				q.data[q.rear].front = cur_row;
				q.data[q.rear].rear = cur_column - 1;
				q.data[q.rear++].count = cur_count + 1;
			}
		}
	}
	free(q.data);
}

int main()
{
	int		column, row, **check;
	int		idx, temp;
	char	temp_str[101];
	bool	 **maze;

	scanf("%d %d", &column, &row);
	maze = (bool **)malloc(column * sizeof(bool *));
	check = (int **)malloc(column * sizeof(int *));

	idx = -1;
	while (++idx < column)
	{
		scanf("%s", temp_str);
		maze[idx] = (bool *)malloc(row * sizeof(bool));
		check[idx] = (int *)calloc(row, sizeof(int));
		temp = -1;
		while (++temp < row)
			maze[idx][temp] = temp_str[temp] - '0';
	}

	find_by_bfs(maze, check, column, row);
	idx = -1;
	while (++idx < column)
	{
		free(maze[idx]);
		free(check[idx]);
	}
	free(maze);
	free(check);

	return (0);
}