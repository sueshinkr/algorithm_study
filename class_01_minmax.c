#include <stdio.h>

int main()
{
	int	num, integer;
	int	max = -1000001, min = 1000001;

	scanf("%d", &num);

	while (num-- > 0)
	{
		scanf("%d", &integer);
		if (integer > max)
			max = integer;
		if (integer < min)
			min = integer;
	}
	
	printf("%d %d", min, max);
	return (0);
}
