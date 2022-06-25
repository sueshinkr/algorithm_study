#include <stdio.h>

int	matrix_base[5][5];
int	matrix_change[5][5];
int	matrix_temp[5][5];
int	n;
long long b;

static int	cal(int matrix[5][5], int row, int column)
{
	int	ans = 0, idx =- 1;

	while(++idx < n)
		ans += matrix_change[row][idx] * matrix[idx][column];
	return (ans % 1000);
}

static void	change(int matrix[5][5])
{
	int	row, column;

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
			matrix_temp[row][column] = cal(matrix, row, column);
	}
}

static void matrix_cal(int x)
{
	int	row, column;

	if (x == 1)
		;
	else if (x % 2 == 0)
		matrix_cal(x / 2);
	else if (x % 2 == 1)
		matrix_cal((x - 1) / 2);

	change(matrix_change);
	if (x % 2 == 1)
		change(matrix_base);

	row = -1;
	while (++row < n)
	{
		column = -1;		
		while (++column < n)
			matrix_change[row][column] = matrix_temp[row][column];
	}
}

int	main()
{
	int	row, column;

	scanf("%d %lld", &n, &b);

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
		{
			scanf("%d", &matrix_base[row][column]);
			matrix_change[row][column] = matrix_base[row][column];
		}
	}

	matrix_cal(b);

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
			printf("%d ", matrix_change[row][column]);
		printf("\n");
	}
	return (0);
}