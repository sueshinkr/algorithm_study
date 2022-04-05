#include <stdio.h>

int	main()
{
	char	str[1000001];
	int		count[26];
	int		idx;
	int		mostalp;
	int		flag;
	int		result;

	fgets(str, 1000001, stdin);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
			count[str[idx] - 'a']++;
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
			count[str[idx] - 'A']++;
		idx++;
	}
	idx = 0;
	mostalp = -1;
	flag = 0;
	result = 0;
	while (idx < 26)
	{
		if (mostalp < count[idx])
		{
			mostalp = count[idx];
			result = idx;
			flag = 0;
		}
		else if (mostalp == count[idx])
			flag = 1;
		idx++;
	}
	if (flag == 1)
		printf("?");
	else
		printf("%c", result + 'A');
	return (0);
}

