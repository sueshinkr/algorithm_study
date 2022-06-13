#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647
#define MIN(x, y) ((x < y) ? (x) : (y))

int	n, e;
int	**arr;
int *min_dis, *check;

static void	clear_disandcheck()
{
	int	idx = 0;
	while (++idx <= n)
	{
		min_dis[idx] = MAX;
		check[idx] = 0;
	}
}

static void	cal_dis(int from)
{
	int	idx = 0, to = 0, temp_min = MAX;

	check[from] = 1;
	while (++idx <= n)
	{
		if (arr[from][idx] != 0)
		{
			if (min_dis[idx] > min_dis[from] + arr[from][idx])
				min_dis[idx] = min_dis[from] + arr[from][idx];
		}
	}
	
	idx = 0;
	while (++idx <= n)
	{
		if (check[idx] == 0)
		{
			if (min_dis[idx] < temp_min)
			{
				temp_min = min_dis[idx];
				to = idx;
			}
		}
	}
	if (to)
		cal_dis(to);
}


int	main()
{
	int	idx, start, from, to, cost;

	scanf("%d %d", &n, &e);

	arr = (int **)calloc((n + 1), sizeof(int *));
	idx = 0;
	while (++idx <= n)
		arr[idx] = (int *)calloc((n + 1), sizeof(int));
	check = (int *)malloc((n + 1) * sizeof(int));
	min_dis = (int *)malloc((n + 1) * sizeof(int));
	clear_disandcheck();

	scanf("%d", &start);

	idx = -1;
	while (++idx < e)
	{
		scanf("%d %d %d", &from, &to, &cost);
		arr[from][to] = cost;
	}

	min_dis[start] = 0;
	cal_dis(start);

	idx = 0;
	while(++idx <= n)
	{
		if (min_dis[idx] == MAX)
			printf("INF\n");
		else
			printf("%d\n", min_dis[idx]);
	}
	return (0);
}