#include <stdio.h>

int	matrix_base[5][5];
int	matrix_change[5][5];
int	matrix_temp[5][5];
int	n;
long long b;

static int	cal(int matrix1[5][5], int matrix2[5][5], int row, int column)
{
	int	ans = 0, idx =- 1;

	while(++idx < n)
		ans += matrix1[row][idx] * matrix2[idx][column];
	return (ans % 1000);
}

static void	change_matrix(int matrix1[5][5], int matrix2[5][5])
{
	int	row, column;

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
		{
			matrix_temp[row][column] = 0;
			matrix_temp[row][column] = cal(matrix1, matrix2, row, column);
		}
	}

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
			matrix1[row][column] = matrix_temp[row][column];
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
			scanf("%d", &matrix_base[row][column]);
		matrix_change[row][row] = 1;
	}

	while (b)
	{
		if (b % 2 == 1)
			change_matrix(matrix_change, matrix_base);
		if (b > 1)
			change_matrix(matrix_base, matrix_base);
		b /= 2;
	}

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < n)
			printf("%d ", matrix_change[row][column] % 1000);
		printf("\n");
	}
	return (0);
}
