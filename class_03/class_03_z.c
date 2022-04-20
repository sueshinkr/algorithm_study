#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void z_recur(int **arr, int size, int row_idx, int column_idx, int *idx)
{
	if (size > 2)
	{
		z_recur(arr, size / 2, 0, 0, idx);
		z_recur(arr, size / 2, size / 2, 0, idx);
		z_recur(arr, size / 2, 0, size / 2, idx);
		z_recur(arr, size / 2, size / 2, size / 2, idx);
	}
	else
	{
		arr[row_idx][column_idx] = *idx++;
		arr[row_idx][column_idx + 1] = *idx++;
		arr[row_idx + 1][column_idx] = *idx++;
		arr[row_idx + 1][column_idx + 1] = *idx++;
	}


}

int main()
{
	int	num, size, row, column, **arr, idx = -1;

	scanf("%d %d %d", &num, &row, &column);
	size = pow(2, num);
	arr = (int **)malloc(size * sizeof(int *));
	while (++idx < column)
		arr[idx] = (int *)calloc(size, sizeof(int));

	idx = 0;
	z_recur(arr, size, 0, 0, &idx);

	printf("%d", arr[row - 1][column - 1]);
	return (0);
}
