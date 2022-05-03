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
	int	n, m, idx, column = 0, row = 0, count_one, count_all;
	int check_B = 0, check_W = 0, min = 32;
	char **board, BorW = 'B';

	scanf("%d %d", &n, &m);
	board = (char **)malloc(n * sizeof(char *));
	
	idx = -1;
	while (++idx < n)
	{
		board[idx] = (char *)malloc(m * sizeof(char));
		scanf("%s", board[idx]);
	}

	while (n - row >= 8)
	{
		column = 0;
		while (m - column >= 8)
		{	
			check_B = 0;
			check_W = 0;
			count_all = -1;
			while (++count_all < 8)
			{
				count_one = -1;
				while (++count_one < 8)
				{
					if (board[row + count_all][column + count_one] != BorW)
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
			column++;
		}
		row++;
	}

	idx = -1;
	while (++idx < n)
		free(board[idx]);
	free(board);

	printf("%d", min);
	return (0);
}
