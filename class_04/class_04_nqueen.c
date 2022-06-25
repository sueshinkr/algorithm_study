#include <stdio.h>
#define ABS(x) ((x < 0) ? -(x) : x)

int	chess[15];
int	n, count = 0;

static void	check(int row)
{
	int	idx = -1, before_queen, possible;

	if (row == n)
	{
		count++;
		return ;
	}

	while (++idx < n)
	{
		chess[row] = idx;
		
		possible = 1;
		before_queen = -1;
		while (++before_queen < row)
		{
			if (idx == chess[before_queen] || ABS(idx - chess[before_queen]) == row - before_queen)
			{
				possible = 0;
				break;
			}
		}
		if (possible == 1)
			check(row + 1);
	}
}

int	main()
{
	scanf("%d", &n);

	check(0);

	printf("%d\n", count);
	return (0);
}