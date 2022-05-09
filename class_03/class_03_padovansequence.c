#include <stdio.h>
#include <stdlib.h>

static int	padovan(int num, int *arr)
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
	int	test_num, num, *arr;
	
	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d", &num);
		arr = (int *)calloc(num + 1, sizeof(int));

		printf("%d\n",padovan(num, arr));
		free(arr);
	}
	return (0);
}
