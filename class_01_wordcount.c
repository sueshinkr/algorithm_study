#include <stdio.h>

int	main()
{
	char	str[1000001];
	int		idx;
	int		flag;
	int		count;

	scanf("%[^\n]s", str);
	idx = 0;
	flag = 0;
	count = 0;
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
