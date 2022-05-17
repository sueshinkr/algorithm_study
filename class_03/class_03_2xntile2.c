#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	n, *arr, idx;

	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	arr[0] = 1, arr[1] = 3;

	idx = 1;
	while (++idx < n)
		arr[idx] = arr[idx - 1] + arr[idx - 2] * 2;

	printf("%d\n", arr[n - 1]);
	free(arr);
	return (0);
}

/*
1 : 1        1
2 : 1 + 2    3
3 : 1 + 4    5
4 : 1 + 6 + 4    11
5 : 1 + 8 + 12    21
6 : 1 + 10 + 24 + 8    43
7 :  85
8 : 171
9 : 
*/
