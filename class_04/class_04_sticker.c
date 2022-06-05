#include <stdio.h>
#include <string.h>

int	n, arr[200001], check[200001] = {0, };

static int dp(int cur)
{
	int	temp;

	if (check[cur] != 0)
		return (check[cur]);
	if (cur == n - 1 || cur == 2 * n - 1)
	{
		check[cur] = arr[cur];
		return (check[cur]);
	}

	if (cur < n - 1)
	{
		temp = dp(cur + 1 + n) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
	}
	if (cur < n - 2)
	{
		temp = dp(cur + 2) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
		temp = dp(cur + 2 + n) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
	}

	if (cur >= n && cur < 2 * n - 1)
	{
		temp = dp(cur + 1 - n) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
	}
	if (cur >= n && cur < 2 * n - 2)
	{
		temp = dp(cur + 2) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
		temp = dp(cur + 2 - n) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
	}

	return (check[cur]);
}



int	main()
{
	int	test_num, idx, temp, max;

	scanf("%d", &test_num);
	
	while (test_num-- > 0)
	{
		scanf("%d", &n);

		idx = -1;
		while (++idx < n * 2)
			scanf("%d", &arr[idx]);
		
		memset(check, 0, sizeof(check));
		max = 0;

		temp = dp(0);
		if (temp > max)
			max = temp;
		temp = dp(n);
		if (temp > max)
			max = temp;
		
		printf("%d\n", max);
	}
}