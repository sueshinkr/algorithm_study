#include <stdio.h>
#include <string.h>
#define MAX(x, y) ((x > y) ? (x) : (y))

int	main()
{
	char	str1[1001], str2[1001];
	int	arr[1001][1001] = {0, };
	int		idx1 = 0, idx2= 0, len1, len2;

	scanf("%s %s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	while (++idx1 <= len1)
	{
		idx2 = 0;
		while (++idx2 <= len2)
		{
			if (str1[idx1] == str2[idx2])
				arr[idx1][idx2] = arr[idx1 - 1][idx2 - 1] + 1;
			else
				arr[idx1][idx2] = MAX(arr[idx1 - 1][idx2], arr[idx1][idx2 - 1]);
		}
	}
	printf("%d\n", arr[idx1 - 1][idx2 - 1]);
	return (0);
}