#include <stdio.h>
#include <string.h>

int	main()
{
	int	a, b, c;
	int	result;
	int	count[10];
	int	idx;

	scanf("%d%d%d", &a, &b, &c);
	result = a * b * c;
	memset(count, 0, sizeof(count));
	while (result > 0)
	{
		count[result % 10]++;
		result /= 10;
	}
	idx = 0;
	while (idx < 10)
		printf("%d\n", count[idx++]);
}
