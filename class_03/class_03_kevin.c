#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	int	front, rear;
	int	*data;
}	que;

static void bfs(bool **line, int *kevin, int num, int point)
{
	int	cur, idx, *temp_kevin;
	que q;

	q.front = 0;
	q.rear = 0;
	q.data = (int *)calloc(num + 1, sizeof(int));
	temp_kevin = (int *)calloc(num + 1, sizeof(int));

	q.data[q.rear++] = point;

	while (q.rear > q.front)
	{
		cur = q.data[q.front++];
		idx = 0;
		while (++idx <= num)
		{
			if (line[cur][idx])
			{
				if (!temp_kevin[idx] && idx != point)
				{
					temp_kevin[idx] = temp_kevin[cur] + 1;
					q.data[q.rear++] = idx;
				}
			}
		}
	}
	
	idx = 0;
	while (++idx <= num)
		kevin[point] += temp_kevin[idx];
	
	free(temp_kevin);
	free(q.data);
}

int main()
{
	int	num, line_num, *kevin, point_a, point_b, idx, ans, min = 500000;
	bool	**line;

	scanf("%d %d", &num, &line_num);

	kevin = (int *)calloc(num + 1, sizeof(int));
	line = (bool **)malloc((num + 1) * sizeof(bool *));
	idx = -1;
	while (++idx <= num)
		line[idx] = (bool *)calloc(num + 1, sizeof(bool));

	idx = -1;
	while (++idx < line_num)
	{
		scanf("%d %d", &point_a, &point_b);
		line[point_a][point_b] = true;
		line[point_b][point_a] = true;
	}
	
	idx = 0;
	while (++idx <= num)
	{
		bfs(line, kevin, num, idx);
		if (min > kevin[idx])
		{
			min = kevin[idx];
			ans = idx;
		}
	}
	printf("%d", ans);

	idx = -1;
	while (++idx <= num)
		free(line[idx]);
	free(line);
	free(kevin);
	return (0);
}