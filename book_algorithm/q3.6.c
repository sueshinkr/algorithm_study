#include <stdio.h>
#include <limits.h>

int main()
{
	int	k, n, x, y, count = 0;

	scanf("%d %d", &k, &n);

	x = -1;
	while (++x <= k)
	{
		y = -1;
		while (++y <= k)
		{
			if (n - (x + y) >= 0 && n - (x + y) <= k)
				count++;
		}
	}
	printf("%d\n", count);
	return (0);
}