#include <stdio.h>

int	arr[123456 * 2 + 1] = {0, };

int	main()
{
	int	check, idx, temp, count = 0;

	idx = 1;
	while (++idx <= 123456 * 2)
		arr[idx] = 1;

	idx = 2;
	while (idx * idx <= 123456 * 2)
	{
		if (arr[idx] != 0)
		{
			temp = idx * 2;
			while (temp <= 123456 * 2)
			{
				if (arr[temp] != 0)
					arr[temp] = 0;
				temp += idx;
			}
		}
		if (idx == 2)
			idx++;
		else
			idx += 2;
	}

	idx = 1;
	while (++idx <= 123456 * 2)
	{
		if (arr[idx] != 0)
		{
			count++;
			arr[idx] = count;
		}
	}

	while(1)
	{
		scanf("%d", &check);
		if (check == 0)
			return (0);
		else
		{
			temp = check * 2 + 1;
			while (arr[--temp] == 0)
				;
			idx = check;
			while (arr[++idx] == 0)
				;
			printf("%d\n", arr[temp] - arr[idx] + 1);
		}
	}

	return (0);
}