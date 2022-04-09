#include <stdio.h>
#include <stdlib.h>

static int min_num(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int main()
{
	int	m, n, idx = 0;
	int column = 0, row = 0, count_one, count_all;
	int check_B = 0, check_W = 0, min = 32;
	char **board;
	char BorW = 'B';

	scanf("%d %d", &m, &n);
	board = (char **)malloc(m * sizeof(char *));
	
	while (idx < m)
	{
		board[idx] = (char *)malloc(n * sizeof(char));
		scanf("%s", board[idx++]);
	}

	while (m - column >= 8)
	{
		row = 0;
		while (n - row >= 8)
		{	
			check_B = 0;
			check_W = 0;
			count_all = -1;
			while (++count_all < 8)
			{
				count_one = -1;
				while (++count_one < 8)
				{
					if (board[column + count_all][row + count_one] != BorW)
						check_B++;
					else
						check_W++;
					if (BorW == 'B' && count_one != 7)
						BorW = 'W';
					else if (BorW == 'W' && count_one != 7)
						BorW = 'B';
				}
			}
			min = min_num(min, check_B, check_W);
			row++;
		}
		column++;
	}

	while (--idx >= 0)
		free(board[idx]);
	free(board);

	printf("%d", min);
	return (0);
}
