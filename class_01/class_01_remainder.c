#include <stdio.h>

int main()
{
	int	num[10], remainder[42] = {0, }, idx = 0, count = 0;

	while (idx < 10)
		scanf("%d", &num[idx++]);
	
	idx = 0;
	while (idx < 10)
		remainder[num[idx++] % 42]++;
	
	idx = 0;
	while (idx < 42)
	{
		if (remainder[idx++])
			count++;
	}
	
	printf("%d", count);
	return (0);
}
