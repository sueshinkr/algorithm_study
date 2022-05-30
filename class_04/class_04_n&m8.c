#include <stdio.h>

int	n, m, base[10], arr[10] = {0, };

static int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

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
		arr[len] = base[num];
		recur(num, len + 1);
		num++;
	}
}

int	main()
{
	int	idx = -1;

	scanf("%d %d", &n, &m);

	while (++idx < n)
		scanf("%d", &base[idx]);

	qsort(base, n, sizeof(int), compare);

	recur(0, 0);
	return (0);
}