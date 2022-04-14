#include <stdio.h>

int main()
{
	unsigned int	a, b, c, check, max;

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (c == 0)
			break;
		check = a * a + b * b + c * c;
		max = 0;
		if (a > max)
			max = a;
		if (b > max)
			max = b;
		if (c > max)
			max = c;
		
		if (check - max * max * 2 == 0)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return (0);
}
