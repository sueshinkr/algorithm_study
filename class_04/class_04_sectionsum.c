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

		printf("%d\n", arr[row2 - 1][column2 - 1] - arr[row - 2][column2 - 1] - arr[row2 - 1][column - 2] + arr[row - 2][column - 2]);
	}

	return (0);
}