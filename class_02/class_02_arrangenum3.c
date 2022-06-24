#include <stdio.h>

int main()
{
	int	num, num_arr[10001] = {0, }, temp, idx, idx2;

	scanf("%d", &num);

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
