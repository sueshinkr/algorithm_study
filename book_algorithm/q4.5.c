#include <stdio.h>

static void	find_753(long long k, long long cur, int use, long long *count)
{
	if (cur > k)
		return ;
	if (use == 0b111)
		(*count)++;

	find_753(k, cur * 10 + 7, use | 0b001, count);
	find_753(k, cur * 10 + 5, use | 0b010, count);
	find_753(k, cur * 10 + 3, use | 0b100, count);

}

int	main()
{
	long long	k, count = 0;

	scanf("%lld", &k);

	find_753(k, 0, 0, &count);
	printf("%lld\n", count);
	return (0);
}