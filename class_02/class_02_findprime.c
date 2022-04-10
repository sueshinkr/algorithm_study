#include <stdio.h>
#include <stdlib.h>

int	is_prime(int num)
{
	int	i = 3;

	if ((num != 2 && num % 2 == 0) || num == 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i += 2;
	}

	return (1);
}

int main()
{
	int	m, n, idx, temp;
	int	*arr;

	scanf("%d %d", &m, &n);
	arr = (int *)malloc((n + 1) * sizeof(int));
	
	idx = -1;
	while(++idx <= n)
		arr[idx] = idx;

	idx = 2;
	while(idx * idx <= n)
	{
		if (is_prime(idx) == 1)
		{
			temp = 2;
			while(idx * temp <= n)
			{
				arr[idx * temp] = 0;
				temp++;
			}
		}
		if (idx == 2)
			idx++;
		else
			idx += 2;
	}

	while (m <= n)
	{
		if (arr[m] > 1)
			printf("%d\n", arr[m]);
		m++;
	}

	free(arr);
	return (0);
}
