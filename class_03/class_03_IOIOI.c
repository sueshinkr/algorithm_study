#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num, arr_num, idx, count, ans = 0;
	char	*arr;

	scanf("%d %d", &num, &arr_num);
	arr = (char *)malloc((arr_num + 1) * sizeof(char));
	scanf("%s", arr);

	idx = 0;
	while (idx < arr_num)
	{
		if (arr[idx] == 'I')
		{
			count = 1;
			while (arr[idx + 1] && arr[idx] != arr[idx + 1])
			{
				count++;
				idx++;
			}
			if (count >= num * 2 + 1)
				ans += (count - (num * 2 + 1)) / 2 + 1;
			//printf("idx : %d, count : %d, ans : %d\n", idx, count, ans);
		}
		idx++;
	}
	printf("%d", ans);
	free(arr);
	return (0);
}
