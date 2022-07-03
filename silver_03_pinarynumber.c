#include <stdio.h>

long long	check[91] = {0, };

static long long	fivo(int n)
{
	if (n > 2 && check[n] == 0)
	{
		check[n] = fivo(n - 1) + fivo(n - 2);
		return (check[n]);
	}
	else
		return (check[n]);
}


int	main()
{
	int	n;

	scanf("%d", &n);

	check[1] = 1, check[2] = 1;
	printf("%lld\n", fivo(n));
}