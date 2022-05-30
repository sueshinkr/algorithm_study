#include <stdio.h>

int	n, m, arr[10] = {0, };

static void	recur(int num, int len)
{
	int	idx;
	if (len == m)
	{
		idx = 0;
		while (idx < m - 1)
			printf("%d ", arr[idx++]);
		printf("%d\n", arr[idx]);
		return ;
	}

	while (num < n)
	{
		arr[len] = num + 1;
		recur(num + 1, len + 1);
		num++;
	}
}

int	main()
{
	scanf("%d %d", &n, &m);

	recur(0, 0);
	return (0);
}