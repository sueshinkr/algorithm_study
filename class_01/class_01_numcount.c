#include <stdio.h>

int	main()
{
	int	a, b, c, result, idx, count[10] = {0, };

	scanf("%d%d%d", &a, &b, &c);
	result = a * b * c;
	while (result > 0)
	{
		count[result % 10]++;
		result /= 10;
	}
	idx = 0;
	while (idx < 10)
		printf("%d\n", count[idx++]);
	return (0);
}
