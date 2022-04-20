#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void z_recur(int size, int row, int column, int row_idx, int column_idx, int *ans)
{
	if (size < 2)
		return ;
	if (row < row_idx - size / 2 && column < column_idx - size / 2)
		z_recur(size / 2, row, column, row_idx - size / 2, column_idx - size / 2, ans);
	else if (row < row_idx - size / 2 && column >= column_idx - size / 2)
	{
		*ans += pow(size / 2, 2);
		z_recur(size / 2, row, column, row_idx - size / 2, column_idx, ans);
	}
	else if (row >= row_idx - size / 2 && column < column_idx - size / 2)
	{
		*ans += pow(size / 2, 2) * 2;
		z_recur(size / 2, row, column, row_idx, column_idx - size / 2, ans);
	}
	else if (row >= row_idx - size / 2 && column >= column_idx - size / 2)
	{
		*ans += pow(size / 2, 2) * 3;
		z_recur(size / 2, row, column, row_idx, column_idx, ans);
	}
}

int main()
{
	int	num, size, row, column, ans = 0;

	scanf("%d %d %d", &num, &row, &column);
	size = pow(2, num);

	z_recur(size, row, column, size, size, &ans);

	printf("%d", ans);
	return (0);
}

