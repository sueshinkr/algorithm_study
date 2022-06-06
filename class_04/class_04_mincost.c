#include <stdio.h>

#define MAX 2147483647

int	arr[1001][1001] = {0, };
int	min_cost[1001] = {0, };

int	main()
{
	int	n, bus_n, from, to, cost;

	scanf("%d %d", &n, &bus_n);

	while (bus_n-- > 0)
	{
		scanf("%d %d %d", &from, &to, &cost);
		arr[from][to] = cost;
		min_cost[to] = MAX;
	}

	to = 1;
	while (++to <= n)
	{
		from = 0;
		while (++from <= n)
		{
			if (arr[from][to] != 0)
			{
				cost = arr[from][to] + min_cost[from];
				printf("arr[%d][%d] cost : %d\n", from, to, cost);
				if (cost < min_cost[to])
					min_cost[to] = cost;
			}
		}
	}

	scanf("%d %d", &from, &to);
	printf("%d\n", min_cost[to] - min_cost[from]);

	return (0);
}