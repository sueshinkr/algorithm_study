#include <stdio.h>
#include <stdlib.h>

static void	fibonacci_dp(int n, int *arr)
{
	if (n == 0)
		arr[0] = 0;
	else if (n == 1)
		arr[1] = 1;
	else
	{
		if (arr[n] == 0)
		{
			fibonacci_dp(n - 1, arr);
			fibonacci_dp(n - 2, arr);
			arr[n] = arr[n-1] + arr[n-2];
		}
		else
			return ;
	}
}

int main()
{
	int	test_num, n, *arr;

	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d", &n);
		arr = (int *)calloc((n + 1), sizeof(int));
		fibonacci_dp(n, arr);
		
		if (n == 0)
			printf("1 0\n");
		else
			printf("%d %d\n", arr[n-1], arr[n]);
		
		free(arr);
	}

	return (0);
}
