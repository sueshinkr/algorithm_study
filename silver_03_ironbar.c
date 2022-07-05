#include <stdio.h>


int	main()
{
	char arr[100000];
	int	idx, cur = 0, count = 0;

	scanf("%s", arr);

	idx = -1;
	while (arr[++idx])
	{
		if (arr[idx] == '(' && arr[idx + 1] == ')')
		{
			count += cur;
			idx++;
		}
		else if (arr[idx] == '(')
			cur++;
		else if (arr[idx] == ')')
		{
			cur--;
			count++;
		}
	}

	printf("%d\n", count);
	return (0);
}