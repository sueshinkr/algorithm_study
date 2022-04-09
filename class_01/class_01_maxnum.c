#include <stdio.h>

int	main()
{
	int	num[9];
	int	idx;
	int	max[2];

	idx = 0;
	while (idx < 9)
		scanf("%d", &num[idx++]);
	max[0] = 0;
	max[1] = 0;
	while (--idx >= 0)
	{
		if (max[0] < num[idx])
		{
			max[0] = num[idx];
			max[1] = idx;
		}
	}
	printf("%d\n%d", max[0], max[1] + 1);
	return (0);
}
