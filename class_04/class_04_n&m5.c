#include <stdio.h>
#include <stdlib.h>

int	n, m, base[10], check[10] = {0, }, arr[10] = {0, };

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
		while (check[num] != 0)
			num++;
		if (num >= n)
			break;
		arr[len] = base[num];
		check[num] = 1;

		recur(0, len + 1);
		
		check[num++] = 0;
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
