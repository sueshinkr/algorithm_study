#include <stdio.h>
/*
#include <stdlib.h>

int main()
{
	int	i, j, block, *arr, *level, *time, idx, ans_time, ans_level;
	int	min = 256, max = 0, block_idx, block_temp, level_temp, time_temp;
	scanf("%d %d %d", &i, &j, &block);
	arr = (int *)malloc((i * j) * sizeof(int));

	idx = -1;
	while (++idx < i * j)
	{
		scanf("%d", &arr[idx]);
		if (min > arr[idx])
			min = arr[idx];
		if (max < arr[idx])
			max = arr[idx];
	}

	level = (int *)malloc((max - min + 1) * sizeof(int));
	time = (int *)malloc((max - min + 1) * sizeof(int));

	idx = 0;
	level_temp = min;
	while (idx < max - min + 1)
	{
		level[idx] = level_temp;

		block_temp = block;
		time_temp = 0;
		block_idx = -1;
		while (++block_idx < i * j)
		{
			if (arr[block_idx] > level_temp)
			{	
				time_temp += (arr[block_idx] - level_temp) * 2;
				block_temp += (arr[block_idx] - level_temp);
			}
			else if (arr[block_idx] < level_temp)
			{
				time_temp += (level_temp - arr[block_idx]);
				block_temp -= (level_temp - arr[block_idx]);
			} 
		}

		if (block_temp < 0)
			time[idx] = -1;
		else
			time[idx] = time_temp;

		level_temp++;
		idx++;
	}

	idx = 0;
	ans_time = time[idx];
	ans_level = level[idx];
	while(++idx < max - min + 1)
	{
		if (ans_time > time[idx] && time[idx] != -1)
		{
			ans_time = time[idx];
			ans_level = level[idx];
		}
		else if (ans_time == time[idx])
		{
			if (ans_level < level[idx])
			{
				ans_time = time[idx];
				ans_level = level[idx];
			}
		}
	}

	printf("%d %d", ans_time, ans_level);

	free(arr);
	free(level);
	free(time);
	return (0);
}
*/

int main()
{
	int	i, j, block, ground[257] = {0, }, idx, block_num, block_inven, block_temp, time_temp;
	int	min = 256, max = 0, ans_time, ans_level;
	scanf("%d %d %d", &i, &j, &block);

	idx = -1;
	while (++idx < i * j)
	{
		scanf("%d", &block_temp);
		ground[block_temp]++;
		if (min > block_temp)
			min = block_temp;
		if (max < block_temp)
			max = block_temp;
	}

	block_temp = min; 
	ans_time = 500 * 500 * 256;
	ans_level = 0;
	while(block_temp <= max)
	{
		block_inven = block;
		time_temp = 0;
		block_num = min - 1;
		while (++block_num <= max)
		{	
			if (block_num > block_temp)
			{	
				time_temp += ground[block_num] * (block_num - block_temp) * 2;
				block_inven += ground[block_num] * (block_num - block_temp);
			}
			else if (block_num < block_temp) 
			{
				time_temp += ground[block_num] * (block_temp - block_num);
				block_inven -= ground[block_num] * (block_temp - block_num);
			}
		}
		
		if (block_inven >= 0)
		{
			if (time_temp < ans_time)
			{	
				ans_time = time_temp;
				ans_level = block_temp;
			}
			else if (time_temp == ans_time)
			{
				if (ans_level < block_temp)
					ans_level = block_temp;
			}
		}
		block_temp++;
	}

	printf("%d %d", ans_time, ans_level);
	return (0);
}
