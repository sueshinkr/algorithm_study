#include <stdio.h>
#include <string.h>


int main()
{
	int	num, num_arr[10001], temp, idx, idx2;

	scanf("%d", &num);

	memset(num_arr, 0, sizeof(num_arr));
	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &temp);
		num_arr[temp]++;
	}

	idx = -1;
	while (++idx <= 10000)
	{
		idx2 = -1;
		while (++idx2 < num_arr[idx])
			printf("%d\n", idx);
	}

	return (0);
}
