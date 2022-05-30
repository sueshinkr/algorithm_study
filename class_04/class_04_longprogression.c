#include <stdio.h>

int	num, arr[1000], count[1000];

static int	dp(int cur)
{
	int	idx = cur , check, temp;

	if (cur == num - 1)
		return (1);
	if (count[cur] != 1)
		return (count[cur]);

	check = arr[cur];
	while (++idx < num)
	{	
		if(arr[idx] > check)
		{
			temp = dp(idx) + 1;
			if (count[cur] < temp)
				count[cur] = temp;
		}
	}
	return (count[cur]);
}

int	main()
{
	int	idx, max = 0, temp;

	scanf("%d", &num);

	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &arr[idx]);
		count[idx] = 1;
	}

	idx = -1;
	while (++idx < num)
	{
		if (count[idx] == 1)
		{
			temp = dp(idx);
			if (max < temp)
				max = temp;
		}
	}
	idx = -1;
	while (++idx < num)
		printf("%d ", count[idx]);
	printf("\n::::::::::::::::::\n");


	printf("%d\n", max);
	return (0);
}