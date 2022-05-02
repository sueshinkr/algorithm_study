#include <stdio.h>

int	main()
{
	int		total, repeat, idx1, idx2;
	char	str[20];
	
	scanf("%d", &total);
	while (total-- > 0)
	{
		scanf("%d", &repeat);
		scanf("%s", str);
		idx1 = -1;
		while (str[++idx1])
		{
			idx2 = -1;
			while (++idx2 < repeat)
				printf("%c", str[idx1]);
		}
		printf("\n");
	}
}
