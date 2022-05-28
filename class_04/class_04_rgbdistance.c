#include <stdio.h>
#include <stdlib.h>

int	n;
int	arr[1001][3], check[1001][3] = {0, };

static int	find_min(int idx, int color)
{
	int	sum = 1000000, temp, next_color;

	if (check[idx][color] != 0)
		return (check[idx][color]);

	if (idx == n - 1)
	{
		next_color = -1;
		while (++next_color < 3)
		{
			if (next_color != color)
			{
				temp = arr[idx + 1][next_color];
				if (temp < sum)
					sum = temp;
			}
		}
	}
	else if (check[idx][color] == 0)
	{
		next_color = -1;
		while (++next_color < 3)
		{
			if (next_color != color)
			{
				temp = find_min(idx + 1, next_color);
				if (temp < sum)
					sum = temp;
			}
		}
	}
	sum += arr[idx][color];
	check[idx][color] = sum;
	return (sum);
}

int	main()
{
	int	idx, temp, sum = 1000000;
	
	scanf("%d", &n);

	idx = 0;
	while (++idx <= n)
		scanf("%d %d %d", &arr[idx][0], &arr[idx][1], &arr[idx][2]);
	
	idx = -1;
	while (++idx < 3)
	{
		temp = find_min(1, idx);
		if (temp < sum)
			sum = temp;
	}
	printf("%d\n", sum);
	return (0);
}

/*
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
  int n, cost[1001][3] = { };
  scanf("%d", &n);
  for (int i = 0; i <= n-1; i++){
    scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
  }
  for (int i = 1; i <= n-1; i++){
    cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
    cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
    cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
  }

  printf("%d",min(cost[n-1][0],min(cost[n-1][1],cost[n-1][2])));
  return 0;
}
*/


