#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	num, sum, *arr, count = 0, idx;

	scanf("%d %d", &num, &sum);
	arr = (int *)malloc(num * sizeof(int));
	
	idx = -1;
	while (++idx < num)
		scanf("%d", &arr[idx]);

	idx = num - 1;
	while (1)
	{
		while (sum >= arr[idx])
		{
			sum -= arr[idx];
			count++;
		}
		if (sum == 0)
			break;
		idx--;
	}
	
	printf("%d", count);
	free(arr);
	return (0);
}

/*
9 4791
1
30
40
100
500
1000
5000
10000
50000
>> 배수조건있어서 의미없음
*/