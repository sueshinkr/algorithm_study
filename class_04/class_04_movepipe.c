#include <stdio.h>

int	n, count = 0;
int	arr[16][16];

static void	check(int r, int c, int type)
{
	if (r == n - 1 && c == n - 1)
	{
		count++;
		return ;
	}

	if (type == 1)
	{
		if (c == n - 1)
			return ;
		if (arr[r][c + 1] != 1)
			check(r, c + 1, 1);
		if (r != n - 1 && arr[r][c + 1] != 1 && arr[r + 1][c] != 1 && arr[r + 1][c + 1] != 1)
			check(r + 1, c + 1, 3);
	}
	else if (type == 2)
	{
		if (r == n - 1)
			return ;
		if (arr[r + 1][c] != 1)
			check(r + 1, c, 2);
		if (c != n - 1 && arr[r][c + 1] != 1 && arr[r + 1][c] != 1 && arr[r + 1][c + 1] != 1)
			check(r + 1, c + 1, 3);
	}
	else if (type == 3)
	{
		if (c != n - 1 && arr[r][c + 1] != 1)
			check(r, c + 1, 1);
		if (r != n - 1 && arr[r + 1][c] != 1)
			check(r + 1, c, 2);
		if (c != n - 1 && r != n - 1 && arr[r][c + 1] != 1 && arr[r + 1][c] != 1 && arr[r + 1][c + 1] != 1)
			check(r + 1, c + 1, 3);
	}
}

int	main()
{
	int	r, c;

	scanf("%d", &n);

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
			scanf("%d", &arr[r][c]);
	}

	check(0, 1, 1); // 1 : hor, 2 : ver, 3 : diagonal
	printf("%d\n", count);
}