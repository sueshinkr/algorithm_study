#include <stdio.h>
#include <math.h>

static int	devide(int ans, int a, int b, int c)
{
	long long	temp;

	if (b == 1)
		return (a % c);
	temp = devide(ans, a, b / 2, c);
	if (b % 2 == 0)
		ans = (temp * temp) % c;
	else if (b % 2 == 1)
		ans = ((temp * temp % c) * a) % c;
	return (ans);
}

int	main()
{
	int	a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", devide(1, a, b, c));
	return (0);
}