#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	int	front, rear;
	int	*data;
}	que;

static void	bfs(int **connect, bool *check, int line)
{
	int	cur, idx, count = 0;
	que q;

	q.front = 0;
	q.rear = 0;
	q.data = (int *)calloc(line, sizeof(int));

	q.data[q.rear++] = 1;
	check[1] = true;

	while (q.rear > q.front)
	{
		cur = q.data[q.front++];
		idx = -1;
		while (++idx < line)
		{
			if (connect[idx][0] == cur)
			{
				if (!check[connect[idx][1]])
				{
					count++;
					check[connect[idx][1]] = true;
					q.data[q.rear++] = connect[idx][1];
				}
			}
			if (connect[idx][1] == cur)
			{
				if (!check[connect[idx][0]])
				{
					count++;
					check[connect[idx][0]] = true;
					q.data[q.rear++] = connect[idx][0];
				}
			}
		}
	}
	
	printf("%d", count);
	free(q.data);
}


int main()
{
	int	num, line, **connect, idx;
	bool *check;

	scanf("%d %d", &num, &line);
	check = (bool *)calloc(num + 1, sizeof(bool));
	connect = (int **)malloc(line * sizeof(int *));

	idx = -1;
	while (++idx < line)
	{
		connect[idx] = (int *)malloc(2 * sizeof(int));
		scanf("%d %d", &connect[idx][0], &connect[idx][1]);
	}		

	bfs(connect, check, line);

	idx = -1;
	while (++idx < line)
		free(connect[idx]);
	free(connect);
	free(check);

	return (0);
}