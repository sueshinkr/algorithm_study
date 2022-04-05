#include <stdio.h>

int	main()
{
	int	person;
	int	size;
	int	news[5];
	int	idx;

	scanf("%d%d", &person, &size);
	idx = 0;
	while (idx++ < 5)
		scanf("%d", &news[idx]);
	idx = 0;
	while (idx++ < 5)
	{
		printf("%d", news[idx] - person * size);
		if (idx != 5)
			printf(" ");
	}
	return (0);
}
