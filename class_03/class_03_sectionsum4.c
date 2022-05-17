#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	num, test_num, start, end, idx, *arr;

	scanf("%d %d", &num, &test_num);
	arr = (int *)malloc((num + 1) * sizeof(int));
	arr[0] = 0;

	idx = 0;
	while (++idx <= num)
		scanf("%d", &arr[idx]);

	idx = 0;
	while (++idx <= num)
		arr[idx] += arr[idx - 1];

	idx = -1;
	while (++idx < test_num)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", arr[end] - arr[start - 1]);	
	}

	free(arr);
	return (0);
}