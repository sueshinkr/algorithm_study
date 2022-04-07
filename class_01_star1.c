#include <stdio.h>

int	main()
{
	int	line, num_star;
	int	idx = 0;

	scanf("%d", &line);
	
	while (idx++ < line)
	{
		num_star = 0;
		while (num_star++ < idx)
			printf("*");
		printf("\n");
	}

	return (0);
}
