#include <stdio.h>
#include <stdlib.h>

static long long	padovan(long long num, long long *arr)
{
	if (num < 10)
	{
		if (!arr[num])
			arr[num] = "01112234579"[num] - '0';
	}
	else
	{
		if (!arr[num])
			arr[num] = padovan(num - 1, arr) + padovan(num - 5, arr);
	}
	return (arr[num]);
}

int	main()
{
	int	test_num;
	long long	num, *arr;
	
	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%lld", &num);
		arr = (long long *)calloc(num + 1, sizeof(long long));

		printf("%lld\n",padovan(num, arr));
		free(arr);
	}
	return (0);
}

// num-3 + num-2;
