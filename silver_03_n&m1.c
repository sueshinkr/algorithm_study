#include <stdio.h>
#include <stdbool.h>

int		n, m;
int		arr[8] = {0, };
bool	check[9] = {0, };

static void	recur(int len)
{
	int	idx, num = 0;

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
		if (check[num + 1] != 1)
		{
			arr[len] = num + 1;
			check[num + 1] = 1;
			recur(len + 1);
			check[num + 1] = 0;
		}
		num++;
	}
}

int	main()
{
	scanf("%d %d", &n, &m);

	recur(0);
	return (0);
}