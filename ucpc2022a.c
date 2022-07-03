#include <stdio.h>

int	main()
{
	int	n;

	scanf("%d", &n);

	while(n >= 4)
	{
		printf("long ");
		n -= 4;
	}
	printf("int\n");

	return (0);
}