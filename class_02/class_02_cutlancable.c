#include <stdio.h>
#include <stdlib.h>

int main()
{
	int			keep_lan, need_lan, count, idx = 0, *each_lan, result;
	long long	sum = 0, len, max, min = 1;

	scanf("%d %d", &keep_lan, &need_lan);
	each_lan = (int *)malloc(keep_lan * sizeof(int));

	while (idx < keep_lan)
	{
		scanf("%d", &each_lan[idx]);
		sum += each_lan[idx];
		idx++;
	}

	max = sum / need_lan;
	while (min <= max)
	{	
		len = (max + min) / 2;
		count = 0;
		idx = -1;
		while (++idx < keep_lan)
			count += each_lan[idx] / len;

		if (count >= need_lan)
		{
			min = len + 1;
			result = len;
		}
		else
			max = len - 1;
	}
	
	free(each_lan);
	printf("%d", result);
	return (0);
}

//이진탐색
