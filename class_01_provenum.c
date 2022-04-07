#include <stdio.h>

int	main()
{
	int	uniquenum[5];
	int	idx = 0, provenum = 0;

	while (idx < 5)
	{
		scanf("%d", &uniquenum[idx]);
		provenum += uniquenum[idx] * uniquenum[idx++];
	}
	
	provenum %= 10;
	printf("%d", provenum);

	return (0);
}
