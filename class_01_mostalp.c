#include <stdio.h>

int	main()
{
	char	str[1000001];
	int		count[26];
	int		idx = 0;
	int		mostalp_count = 0;
	int		mostalp = 0;

	fgets(str, 1000001, stdin);

	while (str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
			count[str[idx] - 'a']++;
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
			count[str[idx] - 'A']++;
		idx++;
	}

	idx = 0;
	while (idx < 26)
	{
		if (mostalp_count < count[idx])
		{
			mostalp_count = count[idx];
			mostalp = idx + 'A';
		}
		else if (mostalp_count == count[idx])
			mostalp = '?';
		idx++;
	}
	
	printf("%c", mostalp);
	return (0);
}

