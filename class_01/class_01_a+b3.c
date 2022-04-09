#include <stdio.h>

int main()
{
	int	test, a, b;

	scanf("%d", &test);
	
	while (test-- > 0)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return (0);
}
