#include <stdio.h>

int	main()
{
	int	n, idx, max = -1001, sum;
	int	arr[100000] = {0,};

	scanf("%d", &n);

	idx = -1;
	while (++idx < n)
		scanf("%d", &arr[idx]);

	idx = -1;
	while (++idx < n)
	{
		if (arr[idx] >= 0)
		{
			sum = 0;
			while (arr[idx] + sum > 0 && idx < n)
			{
				if (arr[idx] < 0)
					max = max > sum ? max : sum;
				sum += arr[idx++];
			}
			max = max > sum ? max : sum;
		}
		else if (max < 0 && arr[idx] < 0)
			max = max > arr[idx] ? max : arr[idx];
	}

	printf("%d\n", max);
	return (0);
}