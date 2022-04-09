#include <stdio.h>

int	main()
{
	int	n;
	int	idx;

	scanf("%d", &n);
	idx = 0;
	while (++idx < 10)
		printf("%d * %d = %d\n", n, idx, n * idx);
	return (0);
}
