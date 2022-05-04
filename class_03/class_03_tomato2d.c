#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int	front, rear, count;
	struct queue	*data;
}	que;

static void bfs(int **arr, int column, int row)
{
	int	cur_row, cur_column, cur_count;
	que	q;

	q.front = 0;
	q.rear = 0;
	q.data = (que *)calloc(row * column, sizeof(que));

	cur_row = -1;
	while (++cur_row < row)
	{
		cur_column = -1;
		while (++cur_column < column)
		{
			if (arr[cur_row][cur_column] == 1)
			{
				q.data[q.rear].front = cur_row;
				q.data[q.rear].rear = cur_column;
				q.data[q.rear++].count = 1;
			}
		}
	}

	while (q.rear > q.front)
	{
		cur_row = q.data[q.front].front;
		cur_column = q.data[q.front].rear;
		cur_count = q.data[q.front++].count;

		if (cur_column != column - 1 && arr[cur_row][cur_column + 1] == 0)
		{
			arr[cur_row][cur_column + 1] = 1;
			q.data[q.rear].front = cur_row;
			q.data[q.rear].rear = cur_column + 1;
			q.data[q.rear++].count = cur_count + 1;
		}
		if (cur_column != 0 && arr[cur_row][cur_column - 1] == 0)
		{
			arr[cur_row][cur_column - 1] = 1;
			q.data[q.rear].front = cur_row;
			q.data[q.rear].rear = cur_column - 1;
			q.data[q.rear++].count = cur_count + 1;
		}
		if (cur_row != row - 1 && arr[cur_row + 1][cur_column] == 0)
		{
			arr[cur_row + 1][cur_column] = 1;
			q.data[q.rear].front = cur_row + 1;
			q.data[q.rear].rear = cur_column;
			q.data[q.rear++].count = cur_count + 1;
		}
		if (cur_row != 0 && arr[cur_row - 1][cur_column] == 0)
		{
			arr[cur_row - 1][cur_column] = 1;
			q.data[q.rear].front = cur_row - 1;
			q.data[q.rear].rear = cur_column;
			q.data[q.rear++].count = cur_count + 1;
		}
	}

	cur_row = -1;
	while (++cur_row < row)
	{
		cur_column = -1;
		while (++cur_column < column)
		{
			if (arr[cur_row][cur_column] == 0)
			{
				printf("-1\n");
				return ;
			}
		}
	}

	printf("%d\n", cur_count - 1);
	free(q.data);
}

int	main()
{
	int	column, row, **arr, idx, temp;

	scanf("%d %d", &column, &row);
	arr = (int **)malloc(row * sizeof(int *));

	idx = -1;
	while (++idx < row)
	{
		arr[idx] = (int *)malloc(column * sizeof(int));
		temp = -1;
		while (++temp < column)
			scanf("%d", &arr[idx][temp]);
	}

	bfs(arr, column, row);

	idx = -1;
	while (++idx < row)
		free(arr[idx]);
	free(arr);
	return (0);
}



/*
#include <stdio.h>

int buf[1000000];
char ck[1000][1000];
int main(void)
{
	int n, m, b1=0, b2=0, d=0, i, j;
	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", &d);
			ck[i][j] = d;
				if (ck[i][j]==1)
					buf[b2++]=i*m+j;
		}
	d = 0;
	i = b2;
	while (b1 != b2)
	{
		j = buf[b1++];

		if (j / m > 0 && !ck[j/m-1][j%m])
		{
			buf[i++] = j - m;
			ck[j/m-1][j%m]++;
		}
		if (j / m < n - 1 && !ck[j/m+1][j%m])
		{
			buf[i++] = j + m;
			ck[j/m+1][j%m]++;
		}
		if (j % m > 0 && !ck[j /m][(j%m)-1])
		{
			buf[i++] = j - 1;
			ck[j/m][(j%m)-1]++;
		}
		if (j % m < m - 1 && !ck[j/m][(j%m)+1])
		{
			buf[i++] = j + 1;
			ck[j/m][(j%m)+1]++;
		}
		
		if (b1 == b2)
		{
			d++;
			b2 = i;
		}
	}
	if(d>0)
		d--;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (!ck[i][j])
				d = -1;
	printf("%d\n", d);
}
*/