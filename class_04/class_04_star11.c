#include <stdio.h>
#include <stdlib.h>

char	map[3072][6143];

static void	basic_star(int row, int column)
{
	int	idx = -1;

	map[row - 2][column - 2] = '*';
	map[row - 1][column - 1] = '*', map[row - 1][column - 3] = '*';
	while (++idx < 5)
		map[row][column - idx] = '*';
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

	make_star(n, n - 1, 2 * n - 2);

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < 2 * n - 1)
		{
			if (map[row][column] != '*')
				printf(" ");
			else
				printf("%c", map[row][column]);
		}
		printf("\n");
	}
	return (0);
}
