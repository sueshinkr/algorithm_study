#include <stdio.h>

int main()
{
	int	k, idx, temp, stack_idx = 0, num_arr[100000];

	scanf("%d", &k);

	idx = -1;
	while (++idx < k)
	{
		scanf("%d", &temp);

		if(temp > 0)
			num_arr[stack_idx++] = temp;
		else
			num_arr[stack_idx--] = 0; 
	}

	idx = -1;
	temp = 0;
	while (++idx < stack_idx)
		temp += num_arr[idx];

	printf("%d", temp);
	return (0);
}
