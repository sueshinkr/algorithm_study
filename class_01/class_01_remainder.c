#include <stdio.h>
#include <string.h>

int main()
{
	int	num[10];
	int	remainder[42];
	int	count = 0;
	int	idx = 0;

	while (idx < 10)
		scanf("%d", &num[idx++]);
	
	idx = 0;
	memset(remainder, 0, sizeof(remainder));
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
