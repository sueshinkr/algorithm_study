#include <stdio.h>
#define MAX(x, y) ((x > y) ? (x) : (y))

struct object
{
	int	w;
	int	v;
};

int	dp[100001];
struct object obj[100];

int	main()
{
	int	n, total_w, weight, idx;

	scanf("%d %d", &n, &total_w);

	idx = 0;
	while (++idx <= n)
		scanf("%d %d", &obj[idx].w, &obj[idx].v);

	idx = 0;
	while (++idx <= n)
	{
		weight = total_w + 1;
		while (--weight - obj[idx].w >= 0)
			dp[weight] = MAX(dp[weight], dp[weight - obj[idx].w] + obj[idx].v);
	}
	
	printf("%d\n", dp[total_w]);
	return (0);
}