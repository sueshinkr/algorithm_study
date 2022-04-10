#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num, idx = 0, stack_idx = -1, push_count = 0, push_pop_idx = 0;
	int	*arr, *stack, push_pop[200000];

	scanf("%d", &num);
	arr = (int *)malloc(num * sizeof(int));
	stack = (int *)malloc(num * sizeof(int));

	
	while (idx < num)
	{
		stack[idx] = 0;
		scanf("%d", &arr[idx++]);
	}

	idx = 0;
	while (idx < num)
	{
		if (stack[stack_idx] < arr[idx])
		{
			stack[++stack_idx] = ++push_count;
			push_pop[push_pop_idx++] = 1;
		}
		else if (stack[stack_idx] == arr[idx])
		{
			stack[stack_idx--] = 0;
			idx++;
			push_pop[push_pop_idx++] = -1;
		}
		else
		{
			printf("NO\n");
			return (0);
		}
	}
	
	idx = 0;
	while(idx < push_pop_idx)
	{
		if (push_pop[idx] == 1)
			printf("+\n");
		else
			printf("-\n");
		idx++;
	}

	free(arr);
	free(stack);
	return (0);
}
