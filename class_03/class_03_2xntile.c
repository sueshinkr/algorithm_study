#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	n, *arr, idx;

	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	arr[0] = 1, arr[1] = 2;

	idx = 1;
	while (++idx < n)
		arr[idx] = (arr[idx - 1] + arr[idx - 2]) % 10007;

	printf("%d\n", arr[n - 1]);
	free(arr);
	return (0);
}

/*
1 :          1
2 : 1 + 1    2
3 : 1 + 2    3
4 : 1 + 3 + 1    5
5 : 1 + 4 + 3    8
6 : 1 + 5 + 6 + 1    13
7 : 21
8 : 34
9 : 55
*/
