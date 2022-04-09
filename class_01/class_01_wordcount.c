#include <stdio.h>

int	main()
{
	char	str[1000001];
	int		idx = 0;
	int		flag = 0;
	int		count = 0;

	scanf("%[^\n]s", str);
	
	while (str[idx])
	{
		if (str[idx] == ' ')
			flag = 0;
		else if (flag == 0)
		{	
			count++;
			flag = 1;
		}
		idx++;
	}

	printf("%d", count);
	return (0);
}

// scanf fgets fread?
