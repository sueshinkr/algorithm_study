#include <stdio.h>
#include <stdlib.h>

#define MAX 2147483647

struct to_cost
{
	int	to;
	int	cost;
};

int	arr[1001][1001] = {0, };
int	min_cost[1001] = {0, };

static int compare (const void *a, const void *b)
{
	struct to_cost *one = (struct to_cost *)a;;
	struct to_cost *two = (struct to_cost *)b;;

	return (one->cost - two->cost); 
}

static void	set_mincost(int n, int from)
{
	int	to = 0, line = 0, idx = -1;
	struct to_cost	check[1001];

	printf("from : %d\n", from);
	while(++to <= n)
	{
		//printf(":::%d %d\n", min_cost[from], arr[from][to]);
		if (arr[from][to] != -1 && min_cost[from] + arr[from][to] < min_cost[to])
		{
			printf("from %d to %d\n", from, to);
			min_cost[to] = min_cost[from] + arr[from][to];
			check[line].to = to;
			check[line++].cost = arr[from][to];
		}
	}
	//우선순위 큐를 사용하는 방법도 나중에 시도해볼 것
	if(line == 0)
		return;
	qsort(check, line - 1, sizeof(struct to_cost), compare);

	while (++idx < line)
		set_mincost(n, check[idx].to);
}

int	main()
{
	int	n, bus_n, from, to, cost, final_from, final_to;

	scanf("%d %d", &n, &bus_n);

	from = 0;
	while (++from <= n)
	{
		to = 0;
		while (++to <= n)
			arr[from][to] = -1;
	}

	while (bus_n-- > 0)
	{
		scanf("%d %d %d", &from, &to, &cost);
		if (arr[from][to] == -1)
			arr[from][to] = cost;
		else if (arr[from][to] != -1 && arr[from][to] > cost)
			arr[from][to] = cost;
		min_cost[to] = MAX;
	}

	scanf("%d %d", &final_from, &final_to);	

	min_cost[final_from] = 0;
	set_mincost(n, final_from);
	printf("%d\n", min_cost[final_to]);

	return (0);
}

//다익스트라
