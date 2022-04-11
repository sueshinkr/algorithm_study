#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num, count = 0, idx = 0, flag = 2;
	int	*num_arr;

	scanf("%d", &num);
	num_arr = (int *)malloc(num * sizeof(int));

	idx = -1;
	while (++idx < num)
		num_arr[idx] = idx + 1;

	idx = 0;
	while (1)
	{
		if (count == num - 1)
			break;

		if (flag == 2)
		{	
			num_arr[idx] = 0;
			flag = 0;
			count++;
		}

		while (flag != 2)
		{
			idx = (idx + 1) % num;
			if (num_arr[idx] != 0)
				flag++;
		}
	}

	printf("%d", num_arr[idx]);	
	free(num_arr);
	return (0);
}

/*
규칙으로도 가능
1 / 2 / 2 4 / 2 4 6 8 / 2

n이 2 이상일 때, n에서 n보다 작은 2의 제곱을 뺀 후 x2.

int main()
{
	int	num, temp = 1;

	scanf("%d", &num);

	if (num == 1)
		printf("1");
	else
	{
		temp = 1;
		while (temp * 2 < num)
			temp *= 2;
		printf("%d", (num - temp) * 2);
	}	

	return (0);
}
