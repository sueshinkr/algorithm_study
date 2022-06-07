
#include <stdio.h>

int Max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main()
{
	int test_num, n, row, column;
	int arr[2][100001];
	arr[0][0] = arr[1][0] = 0;

	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d", &n);
		row = -1;
		while (++row < 2)
		{
			column = 0;
			while (++column <= n)
				scanf("%d", &arr[row][column]);
		}

		column = 1;
		while (++column <= n)
		{
			arr[0][column] += Max(arr[1][column - 1], arr[1][column - 2]);
			arr[1][column] += Max(arr[0][column - 1], arr[0][column - 2]);
		}

		printf("%d\n", Max(arr[0][n], arr[1][n]));
	}
	return 0;
}


/*
#include <stdio.h>

int Max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main()
{
	int test_num, n, idx;
	int arr[200002];
	
	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d", &n);
		arr[0] = arr[n + 1] = 0;

		idx = 0;
		while (++idx <= n * 2 + 1)
		{
			if (idx == n + 1)
				continue;
			scanf("%d", &arr[idx]);
		}

		idx = 1;
		while (++idx <= n + 1)
		{
			arr[idx] += Max(arr[idx + n], arr[idx - 1 + n]);
			arr[idx + n + 1] += Max(arr[idx - 1], arr[idx - 2]);
		}
		printf("%d\n", Max(arr[n], arr[n * 2 + 1]));
	}
	return 0;
}
*/



/*
#include <stdio.h>
#include <string.h>

int	n, arr[200001], check[200001] = {0, };

static int dp(int cur)
{
	int	temp;

	if (check[cur] != -1)
		return (check[cur]);
	if (cur == n - 1 || cur == 2 * n - 1)
	{
		check[cur] = arr[cur];
		return (check[cur]);
	}

	if (cur < n - 1)
	{
		temp = dp(cur + 1 + n) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
		if (cur < n - 2)
		{
			temp = dp(cur + 2 + n) + arr[cur];
			if (temp > check[cur])
				check[cur] = temp;
		}
	}

	if (cur >= n && cur < 2 * n - 1)
	{
		temp = dp(cur + 1 - n) + arr[cur];
		if (temp > check[cur])
			check[cur] = temp;
		if (cur < 2 * n - 2)
		{
			temp = dp(cur + 2 - n) + arr[cur];
			if (temp > check[cur])
				check[cur] = temp;
		}
	}
	return (check[cur]);
}

int	main()
{
	int	test_num, idx;

	scanf("%d", &test_num);
	
	while (test_num-- > 0)
	{
		int up, down;

		scanf("%d", &n);

		idx = -1;
		while (++idx < n * 2)
		{
			scanf("%d", &arr[idx]);
			check[idx] = -1;
		}

		up = dp(0), down = dp(n);
		printf("%d\n", up > down ? up : down);
	}
	return (0);
}

*/
