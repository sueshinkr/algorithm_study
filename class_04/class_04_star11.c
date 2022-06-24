#include <stdio.h>

int	map[3073][6144];

static void	basic_star(int row, int column)
{
	int	idx = -1;

	map[row - 2][column - 2] = 1;
	map[row - 1][column - 1] = 1, map[row - 1][column - 3] = 1;
	while (++idx < 5)
		map[row][column - idx] = 1;
}

static void	make_star(int n, int row, int column)
{
	if (n == 3)
		basic_star(row, column);
	if (n > 3)
	{
		make_star(n / 2, row - n / 2, column - n / 2);
		make_star(n / 2, row, column - n);
		make_star(n / 2, row, column);
	}
}

int	main()
{
	int	n;
	int	row, column;
	scanf("%d", &n);

	make_star(n, n, 2 * n - 1);
	row = 0;
	while (++row <= n)
	{
		column = 0;
		while (++column <= 2 * n - 1)
		{
			if (map[row][column] == 0)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	return (0);
}
