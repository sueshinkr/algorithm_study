#include <stdio.h>

int	main()
{
	int	line;
	int	idx;
	int	num_star;

	scanf("%d", &line);
	
	idx = 0;
	while (idx++ < line)
	{
		num_star = 0;
		while (num_star++ < line - idx)
			printf(" ");
		while (num_star++ <= line)
			printf("*");
		printf("\n");
	}
}

