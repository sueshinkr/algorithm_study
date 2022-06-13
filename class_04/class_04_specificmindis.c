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
		if (arr[idx][from] != 0)
		{
			if (min_dis[idx] > min_dis[from] + arr[idx][from])
				min_dis[idx] = min_dis[from] + arr[idx][from];
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
	int	idx, from, to, cost, a, b, route1, route2;

	scanf("%d %d", &n, &e);

	arr = (int **)calloc((n + 1), sizeof(int *));
	idx = 0;
	while (++idx <= n)
		arr[idx] = (int *)calloc((n + 1), sizeof(int));
	check = (int *)calloc((n + 1), sizeof(int));
	min_dis = (int *)malloc((n + 1) * sizeof(int));
	clear_disandcheck();

	idx = -1;
	while (++idx < e)
	{
		scanf("%d %d %d", &from, &to, &cost);
		arr[from][to] = cost;
	}

	scanf("%d %d", &a, &b);

	min_dis[1] = 0;
	cal_dis(1);
	route1 = min_dis[a]; // route 1 : 1->a->b->n
	route2 = min_dis[b]; // route 2 : 1->b->a->n
	if (route1 == MAX || route2 == MAX)
	{
		printf("%d\n", -1);
		return (0);
	}
	clear_disandcheck();

	min_dis[a] = 0;
	cal_dis(a);
	route1 += min_dis[b];
	route2 += min_dis[b];
	clear_disandcheck();
	
	min_dis[b] = 0;
	cal_dis(b);
	route1 += min_dis[n];
	clear_disandcheck();

	min_dis[a] = 0;
	cal_dis(a);
	route2 += min_dis[n];
	clear_disandcheck();

	printf("%d\n", MIN(route1, route2));
	return (0);
}