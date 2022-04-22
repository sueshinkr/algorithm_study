#include <stdio.h>

int main()
{
	char	str[51];
	int		idx, temp = 0, flag = 1, result = 0;

	scanf("%s", str);

	idx = -1;
	while (str[++idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			temp = temp * 10 + str[idx] - '0';
		else
		{
			result += (temp * flag);
			if (str[idx] == '-')
				flag = -1;
			temp = 0;
		}
	}
	result += temp * flag;

	printf("%d", result);
	return (0);
}
