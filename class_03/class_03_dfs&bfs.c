#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
typedef struct queue
{
	int	num;
	struct queue *next;
} que;

static int compare(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return (-1);
	else if (*(int *)a > *(int *)b)
		return (1);
	return (0);
}

static void dfs(int **line, int num, int point)
{
	int	idx, togo;

	if (line[point][0] != -1)
		printf("%d ", point);

	while (1)
	{	
		
		
		line[point][0] = -1;

		idx = 0;
		while(++idx < num)
		{
			togo = line[point][idx];
			if (togo != 0 && line[togo][0] == -1)
				line[point][idx] = 0;
			else if (togo != 0 && line[togo][0] != -1)
			{	
				line[point][idx] = 0;
				break;
			}
		}
		if (idx == num)
			break;

		dfs(line, num, togo);
	}
}

static void check_que(que *head, int togo)
{
	que	*new;

	new = (que *)malloc(sizeof(que));
	new->num = togo;
	new->next = NULL;

	while (head)
	{
		if (!head->next)
		{
			head->next = new;
			break;
		}
		head = head->next;
	}	
}

static void bfs(int **line, int num, int point)
{
	int	idx, togo;
	que *head, *temp;

	head = (que *)malloc(sizeof(que));
	head->num = point;
	head->next = NULL;

	line[point][0] = -1;
	temp = head;
	while (temp)
	{
		idx = 0;
		while (++idx < num)
		{
			togo = line[temp->num][idx];
			if (togo != 0 && line[togo][0] == -1)
				line[point][idx] = 0;
			else if (togo != 0 && line[togo][0] != -1)
			{	
				check_que(head, togo);
				line[togo][0] = -1;
			}
		}
		temp = temp->next;
	}

	while (head)
	{
		temp = head;
		printf("%d ", head->num);
		head = head->next;
		free(temp);
	}
}

int main()
{
	int	num, line_num, point, **line1, **line2, *num_idx, idx;
	int	point_a, point_b;

	scanf("%d %d %d", &num, &line_num, &point);

	line1 = (int **)malloc((num + 1) * sizeof(int *));
	line2 = (int **)malloc((num + 1) * sizeof(int *));
	num_idx = (int *)calloc(num + 1, sizeof(int));

	idx = 0;
	while (idx <= num)
	{
		line1[idx] = (int *)calloc(num, sizeof(int));
		line2[idx++] = (int *)calloc(num, sizeof(int));	
	}
	idx = -1;
	while (++idx < line_num)
	{
		scanf("%d %d", &point_a, &point_b);
		line1[point_a][num_idx[point_a]] = point_b;
		line1[point_b][num_idx[point_b]] = point_a;
		line2[point_a][num_idx[point_a]++] = point_b;
		line2[point_b][num_idx[point_b]++] = point_a;
	}

	idx = 0;
	while (idx <= num)
	{
		qsort(line1[idx], num, sizeof(int), compare);
		qsort(line2[idx++], num, sizeof(int), compare);
	}

	dfs(line1, num, point);
	printf("\n");
	bfs(line2, num, point);

	idx = -1;
	while (++idx <= num)
	{
		free(line1[idx]);
		free(line2[idx]);
	}
	free(line1);
	free(line2);
	free(num_idx);

	return (0);
}
*/
typedef struct queue
{
	int	front, rear;
	int	*data;
}	que;

static void bfs(bool **line, bool *check, int num, int point)
{
	int	cur, idx;
	que q;

	q.front = 0;
	q.rear = 0;
	q.data = (int *)calloc(num + 1, sizeof(int));
	
	q.data[q.rear++] = point;
	check[point] = true;

	while (q.rear > q.front)
	{
		cur = q.data[q.front++];
		printf("%d ", cur);
		idx = 0;
		while (++idx <= num)
		{
			if (line[cur][idx])
			{
				if (!check[idx])
				{
					check[idx] = true;
					q.data[q.rear++] = idx;
				}
			}
		}
	}

	free(q.data);
}

static void dfs(bool **line, bool *check, int num, int point)
{
	int	idx;
	
	check[point] = true;
	printf("%d ", point);

	idx = 0;
	while (++idx <= num)
	{
		if (line[point][idx])
		{
			if (!check[idx])
			{
				check[idx] = true;
				dfs(line, check, num, idx);
			}
		}
	}
}

int main()
{
	int	num, line_num, point, point_a, point_b, idx;
	bool **line, *check;

	scanf("%d %d %d", &num, &line_num, &point);

	line = (bool **)malloc((num + 1)* sizeof(bool *));
	check = (bool *)calloc(num + 1, sizeof(bool));

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

	dfs(line, check, num, point);
	printf("\n");
	idx = -1;
	while (++idx <= num)
		check[idx] = false;
	bfs(line, check, num, point);

	idx = -1;
	while (++idx <= num)
		free(line[idx]);
	free(line);
	free(check);
	return (0);
}

