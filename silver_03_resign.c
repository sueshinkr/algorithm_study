#include <stdio.h>

int	n;
int	t[16];
int	p[16];
int	p_max[16] = {0, };
int	max = 0;

static void check(int idx, int profit)
{
	if (profit < p_max[idx])
		return ;
	else
		p_max[idx] = profit;
	if (idx + t[idx] > n + 1)
		return ;
	else
		profit += p[idx];

	idx += t[idx];
	while(idx <= n)
		check(idx++, profit);
	max = max > profit ? max : profit;
}

int	main()
{
	int	idx;

	scanf("%d", &n);

	idx = 0;
	while (++idx <= n)
		scanf("%d %d", &t[idx], &p[idx]);

	idx = 0;
	while (++idx <= n)
		check(idx, 0);
	printf("%d\n", max);
	return (0);
}