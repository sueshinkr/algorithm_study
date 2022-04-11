#include <stdio.h>

static int	is_prime(int num)
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
	int	num, idx, what_num, temp, count = 0;
	int arr[1001];

	scanf("%d", &num);
	
	idx = -1;
	while(++idx <= 1000)
		arr[idx] = idx;

	idx = 2;
	while(idx * idx <= 1000)
	{
		if (is_prime(idx) == 1)
		{
			temp = 2;
			while(idx * temp <= 1000)
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

	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &what_num);
		if (arr[what_num] > 1)
			count++;
	}

	printf("%d", count);
	return (0);
}
