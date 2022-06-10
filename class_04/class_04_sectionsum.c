#include <stdio.h>

int	main()
{
	int	n, test_num, arr[1024][1024], row, column, row2, column2;

	scanf("%d %d", &n, &test_num);

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
			scanf("%d", &arr[row][column]);
	}

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
		{
			if (row > 0 && column == 0)
				arr[row][column] += arr[row - 1][column];
			else if (row == 0 && column > 0)
				arr[row][column] += arr[row][column - 1];
			else if (row > 0 && column > 0)
				arr[row][column] += arr[row - 1][column] + arr[row][column - 1] - arr[row - 1][column - 1];
		}
	}

	while (test_num-- > 0)
	{
		scanf("%d %d %d %d", &row, &column, &row2, &column2);

		if (row > 1 && column > 1)
			printf("%d\n", arr[row2 - 1][column2 - 1] - arr[row - 2][column2 - 1] - arr[row2 - 1][column - 2] + arr[row - 2][column - 2]);
		else if (row > 1)
			printf("%d\n", arr[row2 - 1][column2 - 1] - arr[row - 2][column2 - 1]);
		else if (column > 1)
			printf("%d\n", arr[row2 - 1][column2 - 1] - arr[row2 - 1][column - 2]);
		else
			printf("%d\n", arr[row2 - 1][column2 - 1]);
	}

	return (0);
}


/*
#include <stdio.h>

int t[1025][1025];

int main()
{
	int n, m, r, c, x1, x2, y1, y2;

	scanf("%d%d", &n, &m);

	for (r=1; r<=n; r++)
		for (c=1; c<=n; c++)
		{
			scanf("%d", &t[r][c]);
			t[r][c] += t[r-1][c] + t[r][c-1] - t[r-1][c-1];
		}

	while (m-->0)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", t[x2][y2] - t[x2][y1-1] - t[x1-1][y2] + t[x1-1][y1-1]);
	}

	return 0;
}
*/
