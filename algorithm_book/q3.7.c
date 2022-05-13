#include <stdio.h>
#include <string.h>
#include <limits.h>

long long	ans = 0;

static void make_sum(char *str, int len, int start, long long sum)
{
	int 		i, j, idx;
	long long	temp;

	i = 0;
	while ((++i + start) <= len)
	{
		idx = start;
		j = i;
		temp = 0;
		while (j-- > 0)
			temp = temp * 10 + str[idx++] - '0';
		if (i + start == len)
		{
			printf("sum + temp : %lld\n", sum + temp);
			ans += (sum + temp);
			break ;
		}
		else
			make_sum(str, len, idx, sum + temp);
	}
}


int	main()
{
	char str[10];

	scanf("%s", str);
	make_sum(str, strlen(str), 0, 0);
	printf("%lld\n", ans);
	return (0);
}

// 나중에 비트연산으로도 도전해보기