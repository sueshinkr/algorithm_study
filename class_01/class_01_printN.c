#include <stdio.h>

int	main()
{
	int	n;
	int	idx;

	scanf("%d", &n);
	idx = 0;
	while (idx < n)
		printf("%d\n", ++idx);
	return (0);
}
