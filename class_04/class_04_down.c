#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int	main()
{
	int	n, row, a, b, c;
	int	max[3], min[3], temp[3];
	int	max_num, min_num;
	
	scanf("%d", &n);

	row = -1;
	while (++row < n)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (row == 0)
		{
			max[0] = a, min[0] = a;
			max[1] = b, min[1] = b;
			max[2] = c, min[2] = c;
		}
		if (row > 0)
		{
			temp[0] = max[0], temp[1] = max[1], temp[2] = max[2];
			max[0] = MAX(temp[0], temp[1]) + a;
			max[1] = MAX(MAX(temp[0], temp[1]), temp[2]) + b;
			max[2] = MAX(temp[1], temp[2]) + c;

			temp[0] = min[0], temp[1] = min[1], temp[2] = min[2];
			min[0] = MIN(temp[0], temp[1]) + a;
			min[1] = MIN(MIN(temp[0], temp[1]), temp[2]) + b;
			min[2] = MIN(temp[1], temp[2]) + c;
		}
	}

	max_num = MAX(MAX(max[0], max[1]), max[2]);
	min_num = MIN(MIN(min[0], min[1]), min[2]);

	printf("%d %d\n", max_num, min_num);
}


/*


#include <stdio.h>

int arr[100000][3], min[100000][3], max[100000][3];
int	n, min_num, max_num;

static void	dp_max(int row)
{
	int	temp;

	if (row == n - 1)
	{
		temp = max[row][0] > max[row][1] ? max[row][0] : max[row][1];
		temp = temp > max[row][2] ? temp : max[row][2];
		max_num = temp;
		return ;
	}

	temp = max[row][0] > max[row][1] ? max[row][0] : max[row][1];
	max[row + 1][0] = temp + arr[row + 1][0];

	temp = max[row][0] > max[row][1] ? max[row][0] : max[row][1];
	temp = temp > max[row][2] ? temp : max[row][2];
	max[row + 1][1] = temp + arr[row + 1][1];

	temp = max[row][1] > max[row][2] ? max[row][1] : max[row][2];
	max[row + 1][2] = temp + arr[row + 1][2];

	dp_max(row + 1);
}

static void	dp_min(int row)
{
	int	temp;

	if (row == n - 1)
	{
		temp = min[row][0] < min[row][1] ? min[row][0] : min[row][1];
		temp = temp < min[row][2] ? temp : min[row][2];
		min_num = temp;
		return ;
	}

	temp = min[row][0] < min[row][1] ? min[row][0] : min[row][1];
	min[row + 1][0] = temp + arr[row + 1][0];

	temp = min[row][0] < min[row][1] ? min[row][0] : min[row][1];
	temp = temp < min[row][2] ? temp : min[row][2];
	min[row + 1][1] = temp + arr[row + 1][1];

	temp = min[row][1] < min[row][2] ? min[row][1] : min[row][2];
	min[row + 1][2] = temp + arr[row + 1][2];

	dp_min(row + 1);
}

int	main()
{
	int row, column;
	
	scanf("%d", &n);

	row = -1;
	while (++row < n)
	{
		column = -1;
		while (++column < 3)
		{
			scanf("%d", &arr[row][column]);
			if (row == 0)
			{
				max[row][column] = arr[row][column];
				min[row][column] = arr[row][column];
			}
			else
			{
				max[row][column] = -1;
				min[row][column] = 1000001;
			}
		}
	}

	dp_max(0);
	dp_min(0);

	printf("%d %d\n", max_num, min_num);
}

*/
