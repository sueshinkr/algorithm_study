#include <stdio.h>

static void	dp(int num, int *count)
{
	if (num == 1 || num == 2 || num == 3)
		(*count)++;

	if (num - 1 > 0)
		dp(num - 1, count);
	if (num - 2 > 0)
		dp(num - 2, count);
	if (num - 3 > 0)
		dp(num - 3, count);
}

int	main()
{
	int	test_num, num, count;

	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d", &num);
		count = 0;

		dp(num, &count);
		printf("%d\n", count);
	}
	return (0);
}

/*
1 : 1        1
2 : 2        1+1, 2
3 : 4        1+1+1, 1+2, 2+1, 3
4 : 7        1+3, 3+1, 2+2
5 : 13       11111, 1112, 1121, 1211, 2111, 122, 212, 221, 113, 131, 311, 23, 32
6 : 
*/
